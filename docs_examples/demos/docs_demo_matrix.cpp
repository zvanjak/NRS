#ifdef NRS_USE_SINGLE_HEADER
#include "NRS.h"
#else
#include "NRSBase.h"

#include "base/Matrix.h"
#include "base/MatrixSym.h"
#include "base/MatrixBandDiag.h"

#include "base/BaseUtils.h"
#endif

using namespace NRS;


void Docs_Demo_Matrix_initializations()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*****         Initializing/creating matrices        *******" << std::endl;

  Matrix<Real>  mat1;                           // empty matrix
  Matrix<Real>  mat2(2, 2);                     // ampty matrix 2 x 2
  Matrix<Real>  mat3(3, 3, { 2.0, 0.7, -1.2, 		// matrix with initialized values
														 1.3, 1.5,  2.0,
													  -0.8, 0.0, -1.0 });     
  Matrix<Real>  mat_unit = Matrix<Real>::GetUnitMatrix(4);

  Matrix<int>   mat_int1(2, 2, { 1, 2, 3, 4 });
  MatrixComplex mat_cmplx1(2, 2, { Complex(-1, 1.5), Complex(-4.3,-2.1),
                                   Complex( 2,-0.5), Complex( 1.7, 3.2) });

  // shorter typing with typedefs
  MatrixInt     mat_int(3, 3);
  MatrixFlt     mat_flt(3, 3);
  MatrixDbl     mat_dbl(mat3);
  MatI          mat_i(3, 3);
  MatF          mat_d(3, 3);
  MatC          mat_c2 = mat_cmplx1;

  std::cout << "mat1 = " << mat1 << std::endl;
  std::cout << "mat2 = " << mat2 << std::endl;
  std::cout << "mat3 = " << mat3 << std::endl;
  std::cout << "mat_unit = " << mat_unit << std::endl;
  std::cout << "mat_int1 = " << mat_int1 << std::endl;
  std::cout << "mat_cmplx1 = " << mat_cmplx1 << std::endl;

  Vector<Real> vec_a({ 1.0, -2.0, 3.0 });
  Matrix<Real> matA = MatrixUtils::RowMatrixFromVector<Real>(vec_a);
  Matrix<Real> matB = MatrixUtils::ColumnMatrixFromVector<Real>(vec_a);

  std::cout << "Vector a = " << vec_a << std::endl;
  std::cout << "Matrix::RowMatrixFromVector(a) = " << matA << std::endl;
  std::cout << "Matrix::ColMatrixFromVector(a) = " << matB << std::endl;

/* OUTPUT
mat1 = Rows: 0 Cols: 0

mat2 = Rows: 2 Cols: 2
[          0,          0,  ]
[          0,          0,  ]

mat3 = Rows: 3 Cols: 3
[          2,        0.7,       -1.2,  ]
[        1.3,        1.5,          2,  ]
[       -0.8,          0,         -1,  ]

mat_unit = Rows: 4 Cols: 4
[          1,          0,          0,          0,  ]
[          0,          1,          0,          0,  ]
[          0,          0,          1,          0,  ]
[          0,          0,          0,          1,  ]

mat_int1 = Rows: 2 Cols: 2
[          1,          2,  ]
[          3,          4,  ]

mat_cmplx1 = Rows: 2 Cols: 2
[   (-1,1.5), (-4.3,-2.1),  ]
[   (2,-0.5),  (1.7,3.2),  ]

Vector a = [              1,              -2,               3]
Matrix::RowMatrixFromVector(a) = Rows: 1 Cols: 3
[          1,         -2,          3,  ]

Matrix::ColMatrixFromVector(a) = Rows: 3 Cols: 1
[          1,  ]
[         -2,  ]
[          3,  ]
*/
  //Matrix<Real> m1(2, 2, { 1.0, -1.0, 1.5, 3.0 });
  //Vector<Real> vecRow = m1.VectorFromRow(0);
  //Vector<Real> vecCol = m1.VectorFromColumn(0);
  //Vector<Real> vecDiag = m1.VectorFromDiagonal();

  //std::cout << "Matrix m1 = " << m1 << std::endl;
  //std::cout << "Vector vecRow = Matrix::VectorFromRow(a, 0)    = " << vecRow << std::endl;
  //std::cout << "Vector vecCol = Matrix::VectorFromColumn(a, 0) = " << vecCol << std::endl;
  //std::cout << "Vector vecCol = Matrix::VectorFromDiagonal(a)  = " << vecDiag << std::endl;
}

void Docs_Demo_Basic_mat_operations()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******         Matrix Basic operations             *******" << std::endl;

  Matrix<Real> m1(2, 2, { 1.0, -1.0,
                          1.5,  3.0 });
  Matrix<Real> m2(2, 2, { -2.5, 3.0, 
                           1,  -1.0 });

  std::cout << "m1 = " << m1 << std::endl;
  std::cout << "m2 = " << m2 << std::endl;

  std::cout << "m1 + m2 = " << m1 + m2 << std::endl;
  std::cout << "m1 - m2 = " << m1 - m2 << std::endl;
  std::cout << "m1 * m2 = " << m1 * m2 << std::endl;
  std::cout << "2.0 * m1 = " << 2.0 * m1 << std::endl;
  std::cout << "m1 * 2.0 = " << m1 * 2.0 << std::endl;
  std::cout << "m1 / 2.0 = " << m1 / 2.0 << std::endl;

  MatrixComplex mat_cmplx1(2, 2, { Complex(-1, 1.5), Complex(-4.3,-2.1),
                                   Complex(2,-0.5),  Complex(1.7, 3.2) });
  MatrixComplex mat_cmplx2(2, 2, { Complex(-2.5, 1.5), Complex(3.0, -2.1),
    															 Complex(1.0, 2.0),  Complex(-1.0, 3.2) });

  std::cout << "mat_cmplx1 = " << mat_cmplx1 << std::endl;
  std::cout << "mat_cmplx2 = " << mat_cmplx2 << std::endl;

  std::cout << "mat_cmplx1 + mat_cmplx2 = " << mat_cmplx1 + mat_cmplx2 << std::endl;
  std::cout << "mat_cmplx1 - mat_cmplx2 = " << mat_cmplx1 - mat_cmplx2 << std::endl;
  std::cout << "mat_cmplx1 * mat_cmplx2 = " << mat_cmplx1 * mat_cmplx2 << std::endl;
  std::cout << "2.0 * mat_cmplx1 = " << Complex(2.0) * mat_cmplx1 << std::endl;
  std::cout << "mat_cmplx1 * Complex(2.0, -1.5) = " << mat_cmplx1 * Complex(2.0, -1.5) << std::endl;
  std::cout << "mat_cmplx1 / 2.0 = " << mat_cmplx1 / 2.0 << std::endl;

/* OUTPUT
m1 = Rows: 2 Cols: 2
[          1,         -1,  ]
[        1.5,          3,  ]

m2 = Rows: 2 Cols: 2
[       -2.5,          3,  ]
[          1,         -1,  ]

m1 + m2 = Rows: 2 Cols: 2
[       -1.5,          2,  ]
[        2.5,          2,  ]

m1 - m2 = Rows: 2 Cols: 2
[        3.5,         -4,  ]
[        0.5,          4,  ]

m1 * m2 = Rows: 2 Cols: 2
[       -3.5,          4,  ]
[      -0.75,        1.5,  ]

2.0 * m1 = Rows: 2 Cols: 2
[          2,         -2,  ]
[          3,          6,  ]

m1 * 2.0 = Rows: 2 Cols: 2
[          2,         -2,  ]
[          3,          6,  ]

m1 / 2.0 = Rows: 2 Cols: 2
[        0.5,       -0.5,  ]
[       0.75,        1.5,  ]

mat_cmplx1 = Rows: 2 Cols: 2
[   (-1,1.5), (-4.3,-2.1),  ]
[   (2,-0.5),  (1.7,3.2),  ]

mat_cmplx2 = Rows: 2 Cols: 2
[ (-2.5,1.5),   (3,-2.1),  ]
[      (1,2),   (-1,3.2),  ]

mat_cmplx1 + mat_cmplx2 = Rows: 2 Cols: 2
[   (-3.5,3), (-1.3,-4.2),  ]
[    (3,1.5),  (0.7,6.4),  ]

mat_cmplx1 - mat_cmplx2 = Rows: 2 Cols: 2
[    (1.5,0),   (-7.3,0),  ]
[   (1,-2.5),    (2.7,0),  ]

mat_cmplx1 * mat_cmplx2 = Rows: 2 Cols: 2
[ (0.15,-15.9), (11.2,-5.06),  ]
[ (-8.95,10.8), (-6.99,-3.46),  ]

2.0 * mat_cmplx1 = Rows: 2 Cols: 2
[     (-2,3), (-8.6,-4.2),  ]
[     (4,-1),  (3.4,6.4),  ]

mat_cmplx1 * Complex(2.0, -1.5) = Rows: 2 Cols: 2
[ (0.25,4.5), (-11.8,2.25),  ]
[  (3.25,-4), (8.2,3.85),  ]

mat_cmplx1 / 2.0 = Rows: 2 Cols: 2
[ (-0.5,0.75), (-2.15,-1.05),  ]
[  (1,-0.25), (0.85,1.6),  ]
*/
}

void Docs_Demo_Matrix_Vector_mul()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******          Matrix-Vector multiplication       *******" << std::endl;

  Vector<Real> v1({ 1.0, 2.0 });
  Matrix<Real> m1(2, 2, { 1.0, -1.0, 1.5, 3.0 });

  std::cout << "v1 = " << v1 << std::endl;
  std::cout << "m1 = " << m1 << std::endl;

  std::cout << "v1 * m1 = " << v1 * m1 << std::endl;
  // when multiplying with vector on the right, we are treating it as a column vector!
  std::cout << "m1 * v1 = " << m1 * v1 << std::endl;

  // combining Complex and Real vectors/matrices requires special functions
  Vector<Complex> v_cmplx_2({ Complex(1.0, 2.0), Complex(2.0, 3.0) });
  Matrix<Complex> m_cmplx_2(2, 2, { Complex(1.0, -1.0), Complex(1.5, 3.0), 
                                    Complex(2.0, 1.0), Complex(1.0, 2.0) });

  std::cout << "v_cmplx_2 = " << v_cmplx_2 << std::endl;
  std::cout << "m_cmplx_2 = " << m_cmplx_2 << std::endl;

  std::cout << "v1        * m_cmplx_2 = " << MatrixUtils::MulVecMat(v1, m_cmplx_2) << std::endl;
  std::cout << "v_cmplx_2 * m1        = " << MatrixUtils::MulVecMat(v_cmplx_2, m1) << std::endl;
  std::cout << "m_cmplx_2 * v1        = " << MatrixUtils::MulMatVec(m_cmplx_2, v1) << std::endl;
  std::cout << "m1        * v_cmplx_2 = " << MatrixUtils::MulMatVec(m1, v_cmplx_2) << std::endl;

/* OUTPUT
v1 = [              1,               2]
m1 = Rows: 2 Cols: 2
[          1,         -1,  ]
[        1.5,          3,  ]

v1 * m1 = [              4,               5]
m1 * v1 = [             -1,             7.5]

v_cmplx_2 = [          (1,2),           (2,3)]
m_cmplx_2 = Rows: 2 Cols: 2
[     (1,-1),    (1.5,3),  ]
[      (2,1),      (1,2),  ]

v1        * m_cmplx_2 = [          (5,1),         (3.5,7)]
v_cmplx_2 * m1        = [        (4,6.5),           (5,7)]
m_cmplx_2 * v1        = [          (4,5),           (4,5)]
m1        * v_cmplx_2 = [        (-1,-1),        (7.5,12)]
*/
}

void Docs_Demo_Matrix_Matrix_mul()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******          Matrix-Matrix multiplication       *******" << std::endl;

  Matrix<Real> m3(2, 3, { 0.5,  1.5, -1.0,
    											3.2, -2.0,  1.0 });
   
  Matrix<Real> m4(3, 4, { 1.0, 0.8, 4.0, 1.3,
                         -2.0, 1.0, 0.0,-1.0,
                          3.0, 0.5, 1.0, 1.0 });

  std::cout << "m3 = " << m3 << std::endl;
  std::cout << "m4 = " << m4 << std::endl;
  std::cout << "m3 * m4 = " << m3 * m4 << std::endl;

  // multiplying Complex and Real matrices requires special functions
  Matrix<Complex> m3_cmplx(2, 3, { Complex(1.4, -1.0), Complex(1.5, 3.0), (2.5, 1.5),
                                   Complex(2.0, 1.5), Complex(1.0, 2.2), (-1.1, 2.8) });

  Matrix<Complex> m5_cmplx = MatrixUtils::MulMat(m3_cmplx, m4);

  std::cout << "m3_cmplx = " << m3_cmplx << std::endl;
  std::cout << "m3_cmplx * m4 = " << m5_cmplx << std::endl;

/* OUTPUT
m3 = Rows: 2 Cols: 3
[          3,        0.5,          1,          1,  ]
[        3.2,         -2,          1,  ]
m3 * m4 = Rows: 2 Cols: 4
[       -5.5,        1.4,          1,      -1.85,  ]
[       10.2,       1.06,       13.8,       7.16,  ]
[         -2,          1,          0,         -1,  ]
m3_cmplx = Rows: 2 Cols: 3
[   (1.4,-1),    (1.5,3),    (1.5,0),  ]
[    (2,1.5),    (1,2.2),    (2.8,0),  ]

m3_cmplx * m4 = Rows: 2 Cols: 4
[   (2.9,-7), (3.37,2.2),   (7.1,-4), (1.82,-4.3),  ]
[ (8.4,-2.9),    (4,3.4),   (10.8,6), (4.4,-0.25),  ]
*/
}

void Docs_Demo_Matrix_invert()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******          Matrix Invert                      *******" << std::endl;

  Matrix<Real> m1(3, 3, { 1.0, 2.0, -1.0,
                         -1.0, 5.0,  6.0,
                          3.0, 1.0,  1.0 });

  std::cout << "m1       = " << m1 << std::endl;
  auto m2 = m1.GetInverse();

  std::cout << "m2 (inv) = " << m2 << std::endl;

  auto munit = m1 * m2;
  std::cout << "m1 * m2 = " << munit << std::endl;

  /* OUTPUT
  m1       = Rows: 3 Cols: 3
[          1,          2,         -1,  ]
[         -1,          5,          6,  ]
[          3,          1,          1,  ]

m2 (inv) = Rows: 3 Cols: 3
[    -0.0189,    -0.0566,      0.321,  ]
[      0.358,     0.0755,    -0.0943,  ]
[     -0.302,     0.0943,      0.132,  ]

m1 * m2 = Rows: 3 Cols: 3
[          1,  -1.39e-17,  -2.78e-17,  ]
[   2.22e-16,          1,          0,  ]
[          0,  -2.78e-17,          1,  ]
*/
}

void Docs_Demo_Matrix_transpose()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******          Matrix Transpose                   *******" << std::endl;

  Matrix<Real> m1(2, 2, { 1.0, -1.0, 
                          1.5, 3.0 });
  std::cout << "m1          = " << m1 << std::endl;
  std::cout << "m1 (transp) = " << m1.GetTranspose() << std::endl;

  Matrix<Real> m2(2, 4, { 1.0, -1.0, 2.0, 1.0,
                          1.5,  3.0, 7.0, 4.0 });
  std::cout << "m2          = " << m2 << std::endl;
  std::cout << "m2 (transp) = " << m2.GetTranspose() << std::endl;

  Matrix<Real> m3(5, 1, { 1.0, -1.0, 2.0, 1.0, 3.0 });
  std::cout << "m3          = " << m3 << std::endl;
  std::cout << "m3 (transp) = " << m3.GetTranspose() << std::endl;

  // we can do transposing in place (BUT ONLY FOR SQUARE MATRICES!)
  m1.Transpose();
  std::cout << "ms (after transposing) = " << m1 << std::endl;

/* OUTPUT
m1          = Rows: 2 Cols: 2
[          1,         -1,  ]
[        1.5,          3,  ]

m1 (transp) = Rows: 2 Cols: 2
[          1,        1.5,  ]
[         -1,          3,  ]

m2          = Rows: 2 Cols: 4
[          1,         -1,          2,          1,  ]
[        1.5,          3,          7,          4,  ]

m2 (transp) = Rows: 4 Cols: 2
[          1,        1.5,  ]
[         -1,          3,  ]
[          2,          7,  ]
[          1,          4,  ]

m3          = Rows: 5 Cols: 1
[          1,  ]
[         -1,  ]
[          2,  ]
[          1,  ]
[          3,  ]

m3 (transp) = Rows: 1 Cols: 5
[          1,         -1,          2,          1,          3,  ]

ms (after transposing) = Rows: 2 Cols: 2
[          1,        1.5,  ]
[         -1,          3,  ]
*/
}

void Docs_Demo_Demo_Matrix_Sym()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******                  Matrix Sym                 *******" << std::endl;
  std::cout << "***********************************************************" << std::endl;

  MatrixSym<Real> a(3, { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 });

  a.Print(std::cout, 10, 3);

  MatrixSym<Real> b(3, { 1.0,
                        2.0, 3.0,
                        4.0, 5.0, 6.0 });

  b.Print(std::cout, 10, 3);

/* OUTPUT
Rows: 3
[          1,          2,          4,  ]
[          2,          3,          5,  ]
[          4,          5,          6,  ]
Rows: 3
[          1,          2,          4,  ]
[          2,          3,          5,  ]
[          4,          5,          6,  ]
*/
}

void Docs_Demo_Demo_Matrix_Tridiag()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******               Matrix Tridiag                *******" << std::endl;
  std::cout << "***********************************************************" << std::endl;

  // Dim: 4
  // [          4,          1,          0,          0,  ]
  // [        4.5,        1.5,          2,          0,  ]
  // [          0,          9,          6,          3,  ]
  // [          0,          0,         10,          7,  ]

  // initializing with 3 vectors
  TridiagonalMatrix<Real> a(4, Vector<Real>{ 0.0, 4.5, 9.0, 10.0 }, Vector<Real>{ 4.0, 1.5, 6.0, 7.0 }, Vector<Real>{ 1.0, 2.0, 3.0, 0.0 });

  // initializing with values in single initializer list
  TridiagonalMatrix<Real> b(4, { 4.0, 1.0,
                                  4.5, 1.5,  2.0,
                                       9.0,  6.0, 3.0,
                                            10.0, 7.0 });

  Matrix<Real> c(4, 4, { 4.0, 1.0, 0.0, 0.0,
                          4.5, 1.5, 2.0, 0.0,
                          0.0, 9.0, 6.0, 3.0,
                          0.0, 0.0, 10.0, 7.0 });
  Vector<Real> rhs{ 1.0, 2.0, 3.0, 4.0 };

  a.Print(std::cout, 10, 3);
  b.Print(std::cout, 10, 3);
  std::cout << "rhs: " << rhs << std::endl;

  Vector<Real> sol_a(4), sol_b(4);

  a.Solve(rhs, sol_a);
  b.Solve(rhs, sol_b);

  std::cout << "sol_a: " << sol_a << std::endl;
  std::cout << "sol_b: " << sol_b << std::endl;

  std::cout << "Tridiag sol_a mul" << c * sol_a << std::endl;
  std::cout << "Tridiag sol_b mul" << c * sol_b << std::endl;

/* OUTPUT
Dim: 4
[          4,          1,          0,          0,  ]
[        4.5,        1.5,          2,          0,  ]
[          0,          9,          6,          3,  ]
[          0,          0,         10,          7,  ]
Dim: 4
[          4,          1,          0,          0,  ]
[        4.5,        1.5,          2,          0,  ]
[          0,          9,          6,          3,  ]
[          0,          0,         10,          7,  ]
rhs: [              1,               2,               3,               4]
sol_a: [   0.2345679012,   0.06172839506,    0.4259259259,  -0.03703703704]
sol_b: [   0.2345679012,   0.06172839506,    0.4259259259,  -0.03703703704]
Tridiag sol_a mul[              1,               2,               3,               4]
Tridiag sol_b mul[              1,               2,               3,               4]
 */
}

void Docs_Demo_Demo_Matrix_BandDiag()
{
  std::cout << "***********************************************************" << std::endl;
  std::cout << "*******            Matrix Band diagonal             *******" << std::endl;
  std::cout << "***********************************************************" << std::endl;

  // Dim: 4
  // [          4,          1,          0,          0,  ]
  // [        4.5,        1.5,          2,          0,  ]
  // [          0,          9,          6,          3,  ]
  // [          0,          0,         10,          7,  ]
  Matrix<Real> mat(4, 3, { 0.0, 4.0, 1.0,
                           4.5, 1.5, 2.0,
                           9.0, 6.0, 3.0,
                          10.0, 7.0, 0.0 });

  BandDiagonalMatrix band1(4, 1, 1, mat);
  band1.Print(std::cout, 10, 3);

  // Dim: 7
  // [      3,      1,      0,      0,      0,      0,      0,  ]
  // [      4,      1,      5,      0,      0,      0,      0,  ]
  // [      9,      2,      6,      5,      0,      0,      0,  ]
  // [      0,      4,      2,      2,      5,      0,      0,  ]
  // [      0,      0,      4,      2,      2,      4,      0,  ]
  // [      0,      0,      0,      3,      8,      4,      6,  ]
  // [      0,      0,      0,      0,      2,      4,      4,  ]
  Matrix<Real> mat2(7, 4, { 0.0, 0.0, 3.0, 1.0,
                            0.0, 4.0, 1.0, 5.0,
                            9.0, 2.0, 6.0, 5.0,
                            4.5, 1.5, 2.0, 5.0,
                            4.5, 1.5, 2.0, 4.0,
                            3.0, 8.0, 4.0, 6.0,
                            2.0, 4.0, 4.0, 0.0 });

  BandDiagonalMatrix band2(7, 2, 1, mat2);
  band2.Print(std::cout, 6, 1);

/* OUTPUT
Dim: 4
[          4,          1,          0,          0,  ]
[        4.5,        1.5,          2,          0,  ]
[          0,          9,          6,          3,  ]
[          0,          0,         10,          7,  ]
Dim: 7
[      3,      1,      0,      0,      0,      0,      0,  ]
[      4,      1,      5,      0,      0,      0,      0,  ]
[      9,      2,      6,      5,      0,      0,      0,  ]
[      0,      4,      2,      2,      5,      0,      0,  ]
[      0,      0,      4,      2,      2,      4,      0,  ]
[      0,      0,      0,      3,      8,      4,      6,  ]
[      0,      0,      0,      0,      2,      4,      4,  ]
*/
}

void Docs_Demo_Matrix()
{
  Docs_Demo_Matrix_initializations();
  Docs_Demo_Basic_mat_operations();
  Docs_Demo_Matrix_Vector_mul();
  Docs_Demo_Matrix_Matrix_mul();
  Docs_Demo_Matrix_invert();
  Docs_Demo_Matrix_transpose();

  Docs_Demo_Demo_Matrix_Sym();
  Docs_Demo_Demo_Matrix_Tridiag();
  Docs_Demo_Demo_Matrix_BandDiag();
}