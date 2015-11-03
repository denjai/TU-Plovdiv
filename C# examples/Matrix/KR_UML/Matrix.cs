namespace UML
{
    using System;
    using System.Text;

    public class Matrix<T> where T : struct, IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T>
    {
        private T[,] elements;
        private int numRows;
        private int numCols;

        public Matrix(int m, int n)
        {
            this.elements = new T[m, n];
            this.NumRows = this.elements.GetLength(0);
            this.NumCols = this.elements.GetLength(1);
        }

        public Matrix(T[,] matrix)
        {
            int m = matrix.GetLength(0);
            int n = matrix.GetLength(1);
            this.elements = new T[m, n];
            this.NumRows = this.elements.GetLength(0);
            this.NumCols = this.elements.GetLength(1);
            for (int i = 0; i < this.NumRows; i++)
            {
                for (int j = 0; j < this.NumCols; j++)
                {
                    this.elements[i, j] = matrix[i, j];
                }
            }
        }

        public int NumRows
        {
            get
            {
                return this.numRows;
            }
            private set
            {
                if (value > 0)
                {
                    this.numRows = value;
                }
                else
                {
                    throw new IndexOutOfRangeException(string.Format("Indexes can not be negative! {0}", value));
                }
            }
        }

        public int NumCols
        {
            get
            {
                return this.numCols;
            }
            private set
            {
                if (value > 0)
                {
                    this.numCols = value;
                }
                else
                {
                    throw new IndexOutOfRangeException(string.Format("Indexes can not be negative! {0}", value));
                }
            }
        }

        public T this[int i, int j]
        {
            get
            {
                if (i < 0 || this.NumRows < i)
                {
                    throw new IndexOutOfRangeException(string.Format("Index {0} is invalid index for row!", i));
                }

                if (j < 0 || this.NumCols < j)
                {
                    throw new IndexOutOfRangeException(string.Format("Index {0} is invalid index for columns!", j));
                }

                return this.elements[i, j];
            }

            set
            {
                if (i < 0 || this.NumRows < i)
                {
                    throw new IndexOutOfRangeException(string.Format("Index {0} is invalid index for row!", i));
                }

                if (j < 0 || this.NumCols < j)
                {
                    throw new IndexOutOfRangeException(string.Format("Index {0} is invalid index for columns!", j));
                }

                this.elements[i, j] = value;
            }
        }

        public static Matrix<T> operator +(Matrix<T> m1, Matrix<T> m2)
        {
            if (m1.NumCols == m2.NumCols && m1.NumRows == m2.NumRows)
            {
                Matrix<T> result = new Matrix<T>(m1.NumRows, m1.NumCols);
                for (int i = 0; i < m1.NumRows; i++)
                {
                    for (int j = 0; j < m1.NumCols; j++)
                    {
                        result[i, j] = (dynamic)m1[i, j] + m2[i, j];
                    }
                }
                return result;
            }
            else
            {
                throw new InvalidOperationException(string.Format("Invalid operation for the selected matrixes! Invalid number of rows or columns."));
            }
        }

        public static Matrix<T> operator -(Matrix<T> m1, Matrix<T> m2)
        {
            if (m1.NumCols == m2.NumCols && m1.NumRows == m2.NumRows)
            {
                Matrix<T> result = new Matrix<T>(m1.NumRows, m1.NumCols);
                for (int i = 0; i < m1.NumRows; i++)
                {
                    for (int j = 0; j < m1.NumCols; j++)
                    {
                        result[i, j] = (dynamic)m1[i, j] - m2[i, j];
                    }

                }
                return result;
            }
            else
            {
                throw new InvalidOperationException(string.Format("Invalid operation for the selected matrixes! Invalid number of rows or columns."));
            }
        }

        public static Matrix<T> operator *(Matrix<T> m1, Matrix<T> m2)
        {
            if (m1.NumCols == m2.NumRows && (m1.NumRows != 0 && m2.NumRows != 0 && m2.NumCols != 0))
            {
                Matrix<T> result = new Matrix<T>(m1.NumRows, m2.NumCols);
                for (int i = 0; i < m1.NumRows; i++)
                {
                    for (int j = 0; j < m1.NumCols; j++)
                    {
                        result[i, j] = (dynamic)m1[i, j] + m2[i, j];
                    }
                }
                for (int i = 0; i < result.NumRows; i++)
                {
                    for (int j = 0; j < result.NumCols; j++)
                    {
                        result[i, j] = (dynamic)0;
                        for (int k = 0; k < m1.NumCols; k++)
                        {
                            checked
                            {
                                result[i, j] = result[i, j] + ((dynamic)m1[i, k] * m2[k, j]);
                            }
                        }
                    }
                }
                return result;
            }
            else
            {
                throw new InvalidOperationException(string.Format("Invalid operation for the selected matrixes! Invalid number of rows or columns."));
            }
        }

        public static bool operator true(Matrix<T> matrix)
        {
            for (int i = 0; i < matrix.NumRows; i++)
            {
                for (int j = 0; j < matrix.NumCols; j++)
                {
                    if ((dynamic)matrix[i, j] == 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public static bool operator false(Matrix<T> matrix)
        {
            for (int i = 0; i < matrix.NumRows; i++)
            {
                for (int j = 0; j < matrix.NumCols; j++)
                {
                    if ((dynamic)matrix[i, j] == 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < this.NumRows; i++)
            {
                for (int j = 0; j < this.NumCols; j++)
                {
                    builder.Append(this.elements[i, j] + " ");
                }
                builder.AppendLine();
            }
            return builder.ToString();
        }

        public Matrix<T> Transpose()
        {
            Matrix<T> transposed = new Matrix<T>(this.NumCols, this.NumRows);
            for (int i = 0; i < this.NumRows; i++)
                for (int j = 0; j < this.NumCols; j++)
                {
                    transposed[j, i] = (dynamic)this.elements[i, j];
                }
            return transposed;
        }
    }
}
