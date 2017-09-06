using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//  Ask user to enter quantity of item purchased
//  Use the input quantity to create an invoice object by calling the constructor of Invoice class
//  Display current value stored in the quantity instance variable by calling the get accessor implicitly
//  Calculate and display the incoive amount by calling the GetINvoiceAmount method. Use string int.
//      to format as a currency.

namespace InvoiceApp
{
    class InvoiceTester
    {
        static void Main(string[] args)
        {
            int quantity;
            decimal amount;
            //  Ask user to enter quantity of item purchased.
            Console.Write("Please enter quantity of the part you want to order: ");

            //  Use input quantity to create an object of Invoice.
            Invoice order = new Invoice(quantity = int.Parse(Console.ReadLine()));
            order.Quantity = quantity; //   set order.Quantity to input value

            //  Retrieve and display current quantity value.
            
            Console.WriteLine($"Quantity ordered: {order.Quantity}");

            //  Calculate invoice amount.
            amount = order.GetInvoiceAmount();
            Console.WriteLine("Total price is: {0:C}",
                amount);
            Console.Write("Press any key to continue . . . ");
            Console.ReadLine();
        }
    }
}
