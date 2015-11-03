namespace KP_UML
{
    using System;
    class Parking
    {
        private int capacity;
        private ParkingPlace[] parkingMap;
        private decimal price;

        public Parking(int capacity, decimal price)
        {
            this.Capacity = capacity;
            this.parkingMap = new ParkingPlace[capacity];
            for (int i = 0; i < this.capacity; i++)
            {
                this.parkingMap[i] = new ParkingPlace();
            }
            this.price = price;
            this.EmptyPlaces = this.Capacity;
        }

        public int Capacity
        {
            get { return this.capacity; }
            set { this.capacity = value; }
        }
        public int EmptyPlaces { get; private set; }
        public decimal Price
        {
            get
            {
                return this.price;
            }
            private set
            {
                if (value > 0)
                {
                    this.price = value;
                }
                else
                {
                    throw new ArgumentOutOfRangeException("Price can not be negative!");
                }
            }
        }
        public void AddTime(int number, int hours)
        {
            if (!this.parkingMap[number - 1].Empty)
            {
                this.parkingMap[number - 1].HoursPaid += hours;
            }
            else
            {
                throw new InvalidOperationException("The parking place is empty");
            }
        }
        public void TakePlace(int number, int hours, Car car)
        {
            if (this.parkingMap[number - 1].Empty)
            {
                this.parkingMap[number - 1].Empty = false;
                this.parkingMap[number - 1].HoursPaid = hours;
                this.parkingMap[number - 1].Arrived = DateTime.Now;
                this.parkingMap[number - 1].Vehicle = car;
                this.EmptyPlaces--;
            }
            else
            {
                throw new ArgumentException("The parking place you selected is not empty");
            }
        }
        public TimeSpan TimeLeft(int num)
        {
            return this.parkingMap[num - 1].TimeLeft();
        }
        public void ClearPlace(int number)
        {
            this.parkingMap[number - 1].Empty = true;
            this.parkingMap[number - 1].HoursPaid = 0;
            this.parkingMap[number - 1].Arrived = DateTime.MinValue;
            this.parkingMap[number - 1].Vehicle = null;
        }
        public int getNumerOfCars()
        {
            return this.Capacity - this.EmptyPlaces;
        }

    }
}
