using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//  Casey Cox
//  Knight's Tour application Type 1
//  Develop an app KnightTour to move knight around chessboard. Board is represented by 8x8 rectangular array board.
//  Squares initialized at 0. Randomly pick an element on the chessboard as the initial position of the knight. Update this value to 1.
//  Then move the knight around the board until either all squares have been visited or no valid move exists. Store numbers 1 through 64 in
//  the squares to indicate sequence of moves made. Knight movement uses standard chess style. Use variables currentRow and currentPosition
//  to indicate the row and column of current position. Use these statements -
//  currentRow += vertical[moveNumber];
//  currentColumn += horizontal[moveNumber];
//  Keep a counter that varies from 1 to 64. Record the latest count in each square Knight moves to. Test each potential move to see if
//  knight has already visited that square, ensure knight does not leave board.

namespace KnightTour
{
    class KnightTour
    {
        private static int[,] board = new int[8, 8];
        private static int[] horizontal = new int[] { 2, 1, -1, -2, -2, -1, 1, 2 };
        private static int[] vertical = new int[] { -1, -2, -2, -1, 1, 2, 2, 1 };
        private static int currentRow;
        private static int currentColumn;

        public static void Main(string[] args)
        {
            Random rand = new Random();
            int moveCounter = 0;
            int randomMove = rand.Next(0, 8);
            int testRow = 0;
            int testColumn = 0;
            bool done = false;
            bool goodMove = true;

            //  get starting coordinates and mark first location
            InitBoard();
            currentRow = (randomMove);
            currentColumn = (randomMove);
            board[currentRow, currentColumn] = ++moveCounter;

            while (!done)
            {
                int moveNumber = 0;
                testRow = currentRow + horizontal[moveNumber];
                testColumn = currentColumn + vertical[moveNumber];
                goodMove = validMove(testRow, testColumn);

                //  test if desired move is valid
                if (goodMove)
                {
                    currentRow = testRow;
                    currentColumn = testColumn;
                    board[currentRow, currentColumn] = ++moveCounter;
                }
                else
                {
                    for (int i = 0; i < 7 && !goodMove; ++i)
                    {
                        moveNumber = ++moveNumber % 8;
                        testRow = currentRow + horizontal[moveNumber];
                        testColumn = currentColumn + vertical[moveNumber];
                        goodMove = validMove(testRow, testColumn);
                        //  test if new move is valid
                        if (goodMove)
                        {
                            currentRow = testRow;
                            currentColumn = testColumn;
                            board[currentRow, currentColumn] = ++moveCounter;
                        }
                    }
                    if (!goodMove)
                    {
                        Console.WriteLine($"The tour ended with {moveCounter} moves.");
                        Console.WriteLine("This was not a full tour.");
                        done = true;                        
                    }
                }
                if (moveCounter == 64)
                {
                    Console.WriteLine($"The tour ended with {moveCounter} moves.");
                    done = true;                   
                }
            }

            DisplayBoard();
            Console.ReadKey();
        }

        public static bool validMove(int testRow, int testColumn)
        {
            int x = testRow;
            int y = testColumn;
            if((((x >= 0) && (x <= 7)) && ((y >= 0) && (y <= 7)) && board[x,y] == 0))
            {
                return true;
            }
            return false;
        }

        public static void DisplayBoard()
        {
            Console.WriteLine("-----------------------");
            for(int r = 0; r < 8; r++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (board[r,c] >= 10)
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

        public static void InitBoard()
        {
            for (int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    board[x, y] = 0;
                }
            }
        }
    }
}