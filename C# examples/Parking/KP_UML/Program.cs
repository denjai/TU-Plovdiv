using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KP_UML
{
    class Program
    {
        static void Main(string[] args)
        {
            //new owner
            Owner owner = new Owner("Ivan", "Petrov", "0887637862");
            Console.WriteLine(owner.getFullName());
            Console.WriteLine(owner.TelNum);
            //new car
            Car car = new Car(CarModel.Nissan, CarColor.blue, "RV9999AK", owner);
            Console.WriteLine(car);

            //new parking
            Parking parking = new Parking(30,2m);
            Console.WriteLine("Number of cars:{0}",parking.getNumerOfCars());
            
            //take 2 places
            parking.TakePlace(4,3,car);
            Car car2 = new Car(CarModel.Mercedes, CarColor.silver, "RV9779AK", owner);
            parking.TakePlace(2,1,car2);
            Console.WriteLine("Number of cars:{0}", parking.getNumerOfCars());

            TimeSpan ts = parking.TimeLeft(2);
            Console.WriteLine("Time left for place 2: "+ts.ToString());
        }
    }
}
