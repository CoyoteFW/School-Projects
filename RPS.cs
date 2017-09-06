using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cox_RPS_Game
{
    class RPS
    {
        static void Main(string[] args)
        {
            //  Variable Declaration
            int counter = 1;
            int max = 0;
            int choiceJack = 0;
            int choiceJill = 0;
            int winnerJack = 0;
            int winnerJill = 0;

            //  Introduction
            Console.Write("How many games of paper-rock-scissors will Jack and Jill play? ");
            max = int.Parse(Console.ReadLine());

            //  While loop to play game
            while(counter <= max)
            {
                //  Output intro text
                Console.WriteLine($"\nGame {counter}\n");
                Console.Write("Jack please enter 1 for Paper, 2 for Rock, 3 for Scissors: ");
                choiceJack = int.Parse(Console.ReadLine());
                Console.Write("Jill please enter 1 for Paper, 2 for Rock, 3 for Scissors: ");
                choiceJill = int.Parse(Console.ReadLine());

                //  if/else check for score
                if(choiceJack == 1 && choiceJill == 2)
                {
                    Console.WriteLine("Jack Wins");
                    winnerJack++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if(choiceJack == 2 && choiceJill == 3)
                {
                    Console.WriteLine("Jack Wins");
                    winnerJack++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if(choiceJack == 3 && choiceJill == 1)
                {
                    Console.WriteLine("Jack Wins");
                    winnerJack++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if(choiceJack == 1 && choiceJill == 3)
                {
                    Console.WriteLine("Jill Wins");
                    winnerJill++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if(choiceJack == 2 && choiceJill == 1)
                {
                    Console.WriteLine("Jill Wins");
                    winnerJill++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if(choiceJack == 3 && choiceJill == 2)
                {
                    Console.WriteLine("Jill Wins");
                    winnerJill++;
                    Console.WriteLine($"Number of games Jack has won so far: {winnerJack}");
                    Console.WriteLine($"Number of games Jill has won so far: {winnerJill}\n");
                    counter++;
                }
                else if (choiceJack == choiceJill)
                {
                    Console.WriteLine("Nobody wins. Game replayed.");
                }
                else
                {
                    Console.WriteLine("ERROR. Invalid input. Game replayed.");
                }
            }
            //  End game score calculation
            if(winnerJack > winnerJill)
            {
                Console.WriteLine("Jack has won more games than Jill");
            }
            else if(winnerJack < winnerJill)
            {
                Console.WriteLine("Jill has won more game than Jack");
            }
            else
            {
                Console.WriteLine("Jack and Jill have won the same number of times");
            }

            Console.Write("Press any key to continue . . .");
            Console.ReadLine();
        }
    }
}
