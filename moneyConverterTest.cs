using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cox_MoneyConverter
{
    class moneyConverterTest
    {
        static void Main(string[] args)
        {
            decimal quantity = 0;
            decimal convertEuro = 0;
            decimal convertPound = 0;
            //  Prompt user
            Console.Write("Enter amount in US dollar: $");

            //  Use input to create object of Convert
            moneyConverter amount = new moneyConverter(quantity = decimal.Parse(Console.ReadLine()));
            amount.Dollar = quantity;   //  set accessor

            //  Calculate conversion
            convertEuro = amount.ToEuro();
            convertPound = amount.ToPound();
            Console.WriteLine($"\nEquivalent amount in Euro: EUR {convertEuro}");
            Console.WriteLine($"\nEquivalent amount in Pound: GBP {convertPound}");
            Console.Write("\nPress any key to continue . . . ");
            Console.ReadLine();
        }
    }
}
