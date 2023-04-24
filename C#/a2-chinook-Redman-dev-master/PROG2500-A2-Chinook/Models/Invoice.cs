using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PROG2500_A2_Chinook.Models
{
    public partial class Invoice
    {
        public string FormattedDate
        {
            get
            {
                return string.Format("Order Date: {0:d/M/yyyy} ", InvoiceDate);
            }
        }

        public string FormattedTotal
        {
            get
            {
                return string.Format("Total: {0:C2} ", Total);
            }
        }

        public string FormattedQuantity
        {
            get
            {
                return string.Format(" Quantity: {0}", InvoiceLines.Sum(invl => invl.Quantity));
            }
        }
    }
}
