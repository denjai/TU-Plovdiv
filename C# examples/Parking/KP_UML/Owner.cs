using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KP_UML
{
    public class Owner
    {
        private string firstName;
        private string lastName;
        private string telNum;

        public Owner(string first, string last, string num)
        {
            this.FirstName = first;
            this.LastName = last;
            this.TelNum = num;
        }

        public Owner(Owner newOwner)
        {
            this.FirstName = newOwner.FirstName;
            this.LastName = newOwner.LastName;
            this.TelNum = newOwner.TelNum;
        }

        public string FirstName
        {
            get { return firstName; }
            set
            {
                if (value.All(Char.IsLetter))
                {
                    firstName = value;
                }
                else
                {
                    throw new ArgumentException("Name must contain only characters!");
                }
            }
        }
        public string LastName
        {
            get { return lastName; }
            set
            {
                if (value.All(Char.IsLetter))
                {
                    this.lastName = value;
                }
                else
                {
                    throw new ArgumentException("Name must contain only characters!");
                }
            }
        }

        public string TelNum
        {
            get { return telNum; }
            set
            {
                if (value.All(Char.IsDigit))
                {
                    telNum = value;
                }
                else
                {
                    throw new ArgumentException("Telephone number must contain only numbers!");
                }
            }
        }
        public string getFullName()
        {
            return this.FirstName + " " + this.lastName;
        }
    }
}
