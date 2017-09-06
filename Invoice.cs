using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//  Casey Cox
//  C# Programming
//  Declare an instance variable quantity type (int). Quantity of item being purchased.
//  Define a constructor that needs one initial quantity value in (). Initializes instance quantity
//  Define a property Quantity with get and set accessors. In set, modify value of instance only
//      if passed value is not negative.
//  Define a method GetInvoiceAmount that calculates and returns invoice amount. Assume unit price is
//      $0.75. Invoice is quantity x price. Use decimals for variables and values related to money.

namespace InvoiceApp
{
    class Invoice
    {
        //  Declaring instance variable
        private int quantity;

        //  Constructor
        public Invoice(int initQuantity)
        {
            Quantity = initQuantity;
        }

        //  Property for instance variable quantity
        public int Quantity
        {
            //  Getting the quantity
            get
            {
                return quantity;
            }
            set
            {
                //  Check if value is negative or not
                if (value >= 0)
                    quantity = value;
            }
        }

        //  Method to calculate invoice amount
        public decimal GetInvoiceAmount()
        {
            decimal amt = Quantity * 0.75m;
            return amt;
        }
    }
}
