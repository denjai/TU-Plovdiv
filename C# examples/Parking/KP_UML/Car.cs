using System.Text;
namespace KP_UML
{
    public class Car
    {
        private CarModel model;
        private string regNumber;
        private CarColor color;
        private Owner owner;

        public Car()
        {

        }
        public Car(CarModel model, CarColor clr, string reg)
        {
            this.color = clr;
            this.model = model;
            this.regNumber = reg;
        }
        public Car(CarModel model, CarColor clr, string reg, Owner owner)
            : this(model, clr, reg)
        {
            this.owner = new Owner(owner);
        }
        public CarModel Model
        {
            get
            {
                return this.model;
            }
            private set
            {
                this.model = value;
            }
        }
        public CarColor Color
        {
            get
            {
                return this.color;
            }
            private set
            {
                this.color = value;
            }
        }
        public string RegNumber
        {
            get
            {
                return this.regNumber;
            }
            set
            {
                this.regNumber = value;
            }
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("Model: " + this.Model + "\n");
            sb.Append("Color: " + this.Color + "\n");
            sb.Append("Registration number: " + this.RegNumber + "\n");
            sb.Append("Owner: " + this.owner.getFullName());
            return sb.ToString();
        }
    }
}
