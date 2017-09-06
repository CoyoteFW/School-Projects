using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//  Casey Cox
//  Knight's Tour Application - Heuristic Algorithm Type
//  Same as before, but label two-dimensional array accessibility with numbers indicating from how many squares each particular
//  square is accessible. On a blank chessboard, each of the 16 squares nearest the center is
//  rated as 8, each corner square is rated as 2, and the other squares have accessibility
//  numbers of 3, 4 or 6. The Knight should always move to the square with the lowest accessibility number. In
//  case of a tie, the Knight may move to any of the tied squares.Therefore, the tour may
//  begin in any of the four corners. [Note: As the Knight moves around the chessboard as
//  more squares become occupied, your app should reduce the accessibility numbers.In this
//  way, at any given time during the tour, each available square’s accessibility number will
//  remain equal to precisely the number of squares from which that square may be
//  reached.] Modify the app to run 64 tours, one starting from each square of the chessboard.

namespace KnightTourHeuristicApp
{
    class Program
    {
        private static int[,] board = new int[8, 8];

        static void Main(string[] args)
        {
            int[] horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
            int[] vertical = { -1, -2, -2, -1, 1, 2, 2, 1 };
            bool[] legal = { false, false, false, false, false, false, false, false };
            int startRow = 0, startColumn = 0;
            int currentRow, currentColumn;
            int firstBestMove;
            int counter;    //  inner loop counter
            int tourCounter = 0;

            //  outer counter loop to cycle through 64 iterations, one for each starting position
            for (int a = 1; a <= 64; a++)
            {
                int[,] warnsdorf = {{2,3,4,4,4,4,3,2},  //  accessibility heuristic board  
                                      {3,4,6,6,6,6,4,3},
                                      {4,6,8,8,8,8,6,4},
                                      {4,6,8,8,8,8,6,4},
                                      {4,6,8,8,8,8,6,4},
                                      {4,6,8,8,8,8,6,4},
                                      {3,4,6,6,6,6,4,3},
                                      {2,3,4,4,4,4,3,2}};

                //  start point
                currentRow = startRow;
                currentColumn = startColumn;

                //  Initialize to 0
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        board[i, j] = 0;
                    }
                }

                //  Init board to first move
                board[currentRow, currentColumn] = 1;

                //  inner loop to cycle through 64 moves
                for (counter = 2; counter <= 64; counter++)
                {
                    //  method call for legal moves and update legal array
                    legalMove(currentRow, currentColumn, vertical, horizontal, board, legal);
                    //  check all legal moves and find first move with lowest heuristic
                    firstBestMove = firstBest(legal, currentRow, currentColumn, vertical, horizontal, warnsdorf);
                    //  if no legal moves, break inner loop
                    if (firstBestMove == -1)
                    {
                        break;
                    }
                    //  modify access heuristic for remaining legal moves
                    modifyAccess(firstBestMove, legal, currentRow, currentColumn, vertical, horizontal, warnsdorf);
                    //  Move Knight
                    currentRow += vertical[firstBestMove];  //  set current row to next move
                    currentColumn += horizontal[firstBestMove]; //  set current column to next move
                    board[currentRow, currentColumn] = counter; //  set value at current position to counter number
                }
                //  print board
                if (counter == 65)
                {
                    Console.WriteLine("\nKnight finished tour.");
                    ++tourCounter;
                    DisplayBoard();
                }
                else
                {
                    Console.WriteLine($"\nThe tour ended with {counter - 1} moves.");
                    Console.WriteLine("This was not a full tour.");
                    DisplayBoard();
                }

                //  increment start point
                startPoint(ref startRow, ref startColumn);
            }
            Console.WriteLine($"\nKnight finished {tourCounter} tours.");
            Console.WriteLine("Press any key to continue . . .");
            Console.ReadKey();
        }
        
        public static void legalMove(int cRow, int cCol, int[] vert, int[] horiz, int[,] board, bool[] legal)
        {
            int moveNumber = 0; //  init possible legal move to 0
            while (moveNumber < 8)
            {
                //  store temp values after pass
                int tempR = cRow + vert[moveNumber];
                int tempC = cCol + horiz[moveNumber];
                //  check for legal boundaries
                if (tempR >= 0 && tempR <= 7 && tempC >= 0 && tempC <= 7)
                {
                    if (board[tempR, tempC] == 0)   //  not visited, on board
                    {
                        legal[moveNumber] = true;
                    }
                    else
                    {
                        legal[moveNumber] = false;
                    }
                }
                else
                {
                    legal[moveNumber] = false;
                }
                //  else store false in legal moves array
                ++moveNumber;
            }
        }

        public static int firstBest(bool[] legal, int cRow, int cCol, int[] vert, int[] horiz, int[,] warnsdorf)
        {
            int minAccess = 8;  //  variable for best access heuristic
            int firstBestMove = -1; //  initialize to impossible value
            //  cycle through all 8 possible moves
            for (int moveNumber = 0; moveNumber < 8; moveNumber++)
            {
                //  if move is illegal, skip remaining
                if (legal[moveNumber] == false)
                {
                    continue;
                }
                int tempR = cRow + vert[moveNumber];
                int tempC = cCol + horiz[moveNumber];

                if (warnsdorf[tempR, tempC] < minAccess)
                {
                    minAccess = warnsdorf[tempR, tempC];
                    firstBestMove = moveNumber;
                }
            }

            return firstBestMove;
        }

        public static void modifyAccess(int firstBest, bool[] legal, int cRow, int cCol, int[] vert, int[] horiz, int[,] warnsdorf)
        {
            //  if move is illegal, skip remaining steps
            for (int moveNumber = firstBest + 1; moveNumber < 8; moveNumber++)
            {
                if (legal[moveNumber] == false)
                {
                    continue;
                }
                //  temp values for legal move
                int tempR = cRow + vert[moveNumber];
                int tempC = cCol + horiz[moveNumber];
                //  decrement access heuristic numbers in remaining legal moves
                --warnsdorf[tempR, tempC];
            }
        }

        public static void DisplayBoard()
        {
            Console.WriteLine("-----------------------");
            for (int r = 0; r < 8; r++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (board[r, c] >= 10)
                    {
                        Console.Write($"{board[r, c]} ");
                    }
                    else
                    {
                        Console.Write($"{board[r, c]}  ");
                    }

                }
                Console.WriteLine();
            }
        }

        public static void startPoint(ref int row, ref int col)
        {
            //  needed to cycle through outer loop properly
            ++col;
            if (col >= 8)
            {
                col = 0;
                ++row;
            }
        }
    }
}
