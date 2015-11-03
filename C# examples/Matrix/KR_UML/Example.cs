using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UML
{
    class Example
    {
        static void Main(string[] args)
        {
            //test constructor
            var matr = new Matrix<int>(4, 5);
            //test indexer
            matr[3, 4] = 8;
            Console.WriteLine("{0}", matr[3, 4]);
            //test ToString override
            Console.WriteLine(matr);

            double[,] first = { { 0, 2, 3, 8 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } };
            double[,] second = { { 1, 2, 3, 8 }, { 1, 2, 3, 6 }, { 1, 2, 8, 4 }, { 1, 0, 3, 4 } };
            //test constructor2
            Matrix<double> arrFirst = new Matrix<double>(first);
            Matrix<double> arrSecond = new Matrix<double>(second);
            Console.WriteLine(arrFirst);
            Console.WriteLine(arrSecond);

            //test operator true
            if (arrFirst)
            {
                Console.WriteLine("There is no zero inside");
            }
            else Console.WriteLine("There is at least one zero inside\n");
            Console.WriteLine("Sum of the two matrices");
            //test opretor +
            Console.WriteLine(arrFirst + arrSecond);
            Console.WriteLine("Substraction of the two matrices");
            //test opreator -
            Console.WriteLine(arrFirst - arrSecond);
            Console.WriteLine("Multiplication of the two matrices");
            //test operator *
            Console.WriteLine(arrFirst * arrSecond);

            Console.WriteLine("Transposed matrix:");
            Matrix<double> transposed = arrFirst.Transpose();
            Console.WriteLine(transposed);
        }
    }
}
