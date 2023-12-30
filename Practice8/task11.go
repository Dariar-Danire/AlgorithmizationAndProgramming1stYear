// Создаёт новую матрицу с заданным кол-вом строк и столбцов, заполненную значениями value
func NewMatrix(rows, cols, value int) Matrix {
	var data = make([][]int, rows)
	for i := 0; i < rows; i++ {
		data[i] = make([]int, cols)

		for j := 0; j < cols; j++ {
			data[i][j] = value
		}
	}

	var m Matrix
	m.data = data

	return m
}

// Возвращает количество строк в матрице
func (m *Matrix) Rows() int {
	return len(m.data)
}

// Возвращает количество столбцов в матрице
func (m *Matrix) Cols() int {
	return len(m.data[0])
}

// Устанавливает элементу с индексом row, col значение value
func (m *Matrix) Set(row, col, value int) {
	m.data[row][col] = value
}

// / Как Set, только получает
func (m *Matrix) Get(row, col int) int {
	return m.data[row][col]
}

// 4 5 6   1 2 3     1 строка на 1 столбец	1 строка на 2 столбец	1 строка на 3 столбец
// 8 9 3 * 1 2 3 ->  2 строка на 1 столбец	2 строка на 2 столбец	2 строка на 3 столбец
// 1 4 8   1 2 3	 3 строка на 1 столбец	3 строка на 2 столбец	3 строка на 3 столбец

// a[i][i] * b[i][i] + a[i][i + 1] * b[i + 1][i] + a[i][i + 2] * b[i + 2][i] + ... + a[i][j] * b[j][i]

func (m *Matrix) Convolution(core *Matrix) Matrix {
	newRows := m.Rows() - core.Rows() + 1
	newCols := m.Cols() - core.Cols() + 1
	newMatrix := NewMatrix(newRows, newCols, 0)

	for i := 0; i < newRows; i++ {
		for j := 0; j < newCols; j++ {
			sum := 0

			for n := 0; n < core.Rows(); n++ {
				for k := 0; k < core.Cols(); k++ {
					sum += m.data[i+n][j+k] * core.Get(n, k)
				}
			}
			newMatrix.Set(i, j, sum)
		}
	}
	return newMatrix
}

func (a *Matrix) Multiplication(b *Matrix) *Matrix {
	matrix := NewMatrix(a.Rows(), b.Cols(), 0)

	for i := 0; i < a.Rows(); i++ {
		for j := 0; j < b.Cols(); j++ {
			for k := 0; k < b.Rows(); k++ {
				matrix.Set(i, j, matrix.Get(i, j)+a.Get(i, k)*b.Get(k, j))
			}
		}
	}
	return &matrix
}

// Добавляет строку, заполненную значениями value ???
func (m *Matrix) AddRow(value int) {
	matrix := NewMatrix(m.Rows()+1, m.Cols(), value)

	for i := 0; i < m.Rows(); i++ {
		for j := 0; j < m.Cols(); j++ {
			matrix.data[i][j] = m.data[i][j]
		}
	}

	m.data = matrix.data
}

// Добавляет столбец, заполненный значением value
func (m *Matrix) AddCol(value int) {
	matrix := NewMatrix(m.Rows(), m.Cols()+1, value)

	for i := 0; i < m.Rows(); i++ {
		for j := 0; j < m.Cols(); j++ {
			matrix.data[i][j] = m.data[i][j]
		}
	}

	m.data = matrix.data
}

// Превращает матрицу в строку, готовую для отображения
func (m *Matrix) String() string {
	var res string = ""

	for i := 0; i < m.Rows(); i++ {
		for j := 0; j < m.Cols(); j++ {
			res += fmt.Sprintf("%d", m.data[i][j]) + " "
		}
		res += "\n"
	}

	return res
}
