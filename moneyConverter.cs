using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cox_MoneyConverter
{
    class moneyConverter
    {
        //  Declare instance variable
        private decimal dollar;

        //  Constructor
        public moneyConverter(decimal initDollar)
        {
            Dollar = initDollar;
        }

        //  Property to access variable
        public decimal Dollar
        {
            get
            {
                return dollar;
            }
            set
            {
                //  Negative check
                if (value >= 0)
                    dollar = value;
            }
        }
        //  Method to convert to Euro
        public decimal ToEuro()
        {
            decimal amt = Dollar * 0.9m;
            return amt;
        }

        //  Method to convert to Pound
        public decimal ToPound()
        {
            decimal amt = Dollar * 0.79m;
            return amt;
        }
    }
}
