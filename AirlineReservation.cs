using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//  Casey Cox
//  Application sells airline tickets until plane is full (Capacity 10 seats). For each customer,
//  ask how many seats they want to reserve. If plane has enough seats available, ask customer to
//  enter the name of each passenger. Otherwise, tell the customer how many seats are available.
//  When the plane is full display list of all passengers.
//  In Main - declare all variables. The passenger names must be in a 10 element string type array
//  called passengers. Also, create an integer type variable numberPassenger to store the number of
//  seats reserved. This will help later when you decide where to place passenger names.
//  Ask user to reserve seats repeatedly until all seats are reserved. Save names in the array passengers
//  and update the numberPassengers.
//  If there are not enough seats, display message and let user know how many seats are left. Then
//  user should be allowed to enter number of seats to reserve again. When all 10 seats are reserved,
//  show user a message and display all passengers' names on the screen.

namespace AirlineReservation
{
    class AirlineReservation
    {
        static void Main(string[] args)
        {
            //  declare variables
            string[] passengers = new string[10];
            int numberPassengers = 0;
            int seatsTotal = 10;

            for (int counter = 0; counter < passengers.Length;)
            {
                numberPassengers = 0;
                while (numberPassengers == 0)
                {
                    Console.Write("How many seats do you need? ");
                    numberPassengers = int.Parse(Console.ReadLine());
                }
                if (numberPassengers <= seatsTotal)
                {
                    for (int i = 0; i < numberPassengers; i++)
                    {
                        Console.Write("Name: ");
                        passengers[i + counter] = Console.ReadLine();
                    }
                    seatsTotal -= numberPassengers;
                    counter += numberPassengers;
                    Console.WriteLine();
                }
                else if (numberPassengers > seatsTotal)
                {
                    Console.WriteLine("Sorry! Only {0} seats left\n", seatsTotal);
                }
                else if (numberPassengers == passengers.Length)
                {
                    break;
                }
            }

            Console.WriteLine("All seats are sold.");
            Console.WriteLine("List of Passengers: ");
            for (int j = 0; j < passengers.Length; j++)
            {
                Console.WriteLine("{0}", passengers[j]);
            }
            Console.Write("Press any key to continue . . .");
            Console.ReadKey();

        }
    }
}
