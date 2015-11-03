namespace KP_UML
{
    using System;
    public class  ParkingPlace
    {
        private Car vehicle;

        public ParkingPlace()
        {
            this.Empty = true;
        }

        public Car Vehicle
        {
            get
            {
                return this.vehicle;
            }
            set
            {
                this.vehicle = value;
            }
        }
        public bool Empty { get; set; }

        public int HoursPaid { get; set; }

        public DateTime Arrived { get; set; }

        public TimeSpan TimeLeft()
        {
            DateTime end = new DateTime();
            end = this.Arrived;
            end = end.AddHours(this.HoursPaid);

            return end - DateTime.Now;
        }

    }
}
