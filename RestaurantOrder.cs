using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// Casey Cox
// Restaurant Order Application
// 31 May, 2017
// C# Programming
//  Application allows multiple customers to view menu and order their food. Application calculates
//  and displays the total amount due on the screen.

namespace RestaurantOrder
{
    class RestaurantOrder
    {
        static void Main(string[] args)
        {
            //  Declaration of variables
            int customers = 0;
            int order = 0;
            decimal price = 0;
            decimal total = 0;

            // Display menu for customers
            Console.WriteLine("Combo 1: Fried chicken with slaw [price: 4.25]");
            Console.WriteLine("Combo 2: roast beef with mashed potato [price: 5.75]");
            Console.WriteLine("Combo 3: Fish and Chips [price: 5.25]");
            Console.WriteLine("Combo 4: soup and salad [price: 3.75]\n");

            // Prompt
            Console.Write("How many customers do you have? ");
            customers = int.Parse(Console.ReadLine());

            //  For loop to ask for order
            for (int count = 0; count < customers; count++)
            {
                //  Repeat tasks for each customer
                Console.Write("Please order food for customer " + (count + 1) + ": ");
                order = int.Parse(Console.ReadLine());
                //  Define switch statement to determine food prices
                switch(order)
                {
                    case 1:
                        price = (decimal)4.25;
                        break;
                    case 2:
                        price = (decimal)5.75;
                        break;
                    case 3:
                        price = (decimal)5.25;
                        break;
                    case 4:
                        price = (decimal)3.75;
                        break;
                }
                //  Calculate total due
                total += price;
            }
            //  Display total amount due
            Console.WriteLine($"Total amount due is: {total:C}");
        }
    }
}
