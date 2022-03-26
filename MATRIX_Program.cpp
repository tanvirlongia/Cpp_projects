#include <iostream>
using namespace std;

/*defining the abstract data type matrix using structures*/
struct matrix 
{
    string name;
    double x[2][2];
}m1,m2;

/*declating all the functions*/
matrix get_matrix1(matrix m1);
matrix get_matrix2(matrix m2);
double getscalar(); 
matrix calc_sum(matrix m1, matrix m2);
matrix calcdiff(matrix m1, matrix m2);
matrix scalar_mult(matrix m1, matrix m2, double scalar);
matrix calc_prod(matrix m1, matrix m2);
matrix calcinv(matrix m1, matrix m2);
void print_matrix(matrix m1, matrix m2, matrix endMatrix);

int main()
{
    /*calling the functions and storing their return value to another variable*/
    matrix matrix1, matrix2;
    matrix1 = get_matrix1(m1);
    matrix2 = get_matrix2(m2);

    int menu;
    do
    {
        cout << "Enter 1 for Sum\n"
                "Enter 2 for Difference\n"
                "Enter 3 for Scalar_Multiplication\n"
                "Enter 4 for Multiplication\n"
                "Enter 5 for Inverse\n"
                "Enter 0 to Exit\n ";
                
        cin >> menu;
        matrix endMatrix;
        double scalar;
        switch (menu)
        {
        /*calling a different function in every case*/
        /*and storing its return value to another variable*/
        /*calling the print function to print the matrices*/
        case 1:
            endMatrix = calc_sum(matrix1, matrix2);
            print_matrix(matrix1, matrix2, endMatrix);
            break;

        case 2:
            endMatrix = calcdiff(matrix1, matrix2);
            print_matrix(matrix1, matrix2, endMatrix);
            break;

        case 3:
            scalar = getscalar();
            endMatrix = scalar_mult(matrix1, matrix2, scalar);
            print_matrix(matrix1, matrix2, endMatrix);
            break;

        case 4:
            endMatrix = calc_prod(matrix1, matrix2);
            print_matrix(matrix1, matrix2, endMatrix);
            break;

        case 5:
            endMatrix = calcinv(matrix1, matrix2);   
            print_matrix(matrix1, matrix2, endMatrix);
            break; 

        default:
            if (menu == 0)
                cout << "exit";
            else
                cout << "invalid";
            break;
        }
    }while (menu!=0);
return 0;
}

/*using the funtion to get the elements of first matrix and returing its value*/
matrix get_matrix1(matrix m1)
{
    cout << "\nEnter the name for Matrix 1: ";
    cin >> m1.name;
	int i, j;
	cout << endl << "Enter elements of matrix 1:" << endl;
	for(i = 0; i < 2; ++i)
	{
		for(j = 0; j < 2; ++j)
		{
			cout << "Enter elements a"<< i + 1 << j + 1 << ": ";
			cin >> m1.x[i][j];
		}
	}
return m1;
} 

/*using the funtion to get the elements of second matrix and returing its value*/
matrix get_matrix2(matrix m2)
{
    cout << "\nEnter the name for Matrix 2: ";
    cin >> m2.name;
    int i,j;
	cout << endl << "Enter elements of matrix 2:" << endl;
	for(i = 0; i < 2; ++i)
	{
		for(j = 0; j < 2; ++j)
		{
			cout << "Enter elements b" << i + 1 << j + 1 << ": ";
			cin >> m2.x[i][j];
		}
	}
return m2;
}

/*using the funtion to get the scalar and returing its value*/
double getscalar()
{
    double scalar;
    cout << "Enter the Scalar: ";
    cin >> scalar;
    return scalar;
}

/*using the function add the two matrices and returing its value*/
/*letting the user decide the way in which to add both matrices*/
/*also initializing the name of the resulting matrix in this function*/
matrix calc_sum(matrix m1, matrix m2)
{
    matrix sum;
    sum.name = "SUM";
    int i, j, k, menu;
    cout << "Enter 1 for Matrix 1 + Matrix 2\n"
            "Enter 2 for Matrix 2 + Matrix 1\n";
                
    cin >> menu;
    switch (menu)
    {
        case 1:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
                {
                    sum.x[i][j] = m1.x[i][j] + m2.x[i][j];
                }
        break;
        case 2:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            {
                sum.x[i][j] = m2.x[i][j] + m1.x[i][j];
            }
        break;
        default:
        cout << "invalid\n";
        break;
    }
return sum;
}

/*using the funtion to subtract the two matrices and returing its value*/
/*letting the user decide the way in which to subtract both matrices*/
/*also initializing the name of the resulting matrix in this function*/
matrix calcdiff(matrix m1, matrix m2)
{
    matrix diff;
    diff.name = "DIFFERENCE";
    int i, j, k, menu;
    cout << "Enter 1 for Matrix 1 - Matrix 2\n"
            "Enter 2 for Matrix 2 - Matrix 1\n";
                
    cin >> menu;
    switch (menu)
    {
        case 1:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
                {
                    diff.x[i][j] = m1.x[i][j] - m2.x[i][j];
                }
        break;
        case 2:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            {
                diff.x[i][j] = m2.x[i][j] - m1.x[i][j];
            }
        break;
        default:
        cout << "invalid\n";
        break;
    }
return diff;
}

/*using the funtion multiply the matrix with the scalar and returing its value*/
/*letting the user decide the matrix with which the scalar is to be multiplied*/
/*also initializing the name of the resulting matrix in this function*/
matrix scalar_mult(matrix m1, matrix m2, double scalar)
{
    matrix smult;
    smult.name = "SCALAR_MULTIPLICATION";
    int i, j, menu;
    cout << "Enter 1 for Scalar * Matrix 1\n"
            "Enter 2 for Scalar * Matrix 2\n";
                
    cin >> menu;
    switch (menu)
    {
        case 1:
            for(i = 0; i < 2; ++i)
	        for(j = 0; j < 2; ++j)
		        {
				    smult.x[i][j] = scalar * m1.x[i][j];
		        }
        break;
        case 2:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            {
                smult.x[i][j] = scalar * m2.x[i][j];
            }
        break;
        default:
        cout << "invalid\n";
        break;
    }
return smult;
}

/*using the funtion to get the multiply the two matrices and returing its value*/
/*letting the user decide the way in which to multiply both matrices*/
/*also initializing the name of the resulting matrix in this function*/  
matrix calc_prod(matrix m1, matrix m2)
{
    matrix mult;
    mult.name = "MULTIPLICATION";
	int i, j, k, menu;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < 2; ++i)
    for(j = 0; j < 2; ++j)
		{
			mult.x[i][j] = 0;
		}

    cout << "Enter 1 for Matrix 1 * Matrix 2\n"
            "Enter 2 for Matrix 2 * Matrix 1\n";
                
    cin >> menu;
    switch (menu)
    {
        case 1:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            for(k=0; k<2; ++k)
            {
                mult.x[i][j] += m1.x[i][k] * m2.x[k][j];
            }
        break;
        case 2:
            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            for(k=0; k<2; ++k)
            {
                mult.x[i][j] += m2.x[i][k] * m1.x[k][j];
            }
        break;
        default:
        cout << "invalid\n";
        break;
    }
return mult;
}

/*using the funtion to get the inverse of the matrix and returing its value*/
/*letting the user decide the matrix whose inverse is to be calculated*/
/*also initializing the name of the resulting matrix in this function*/
matrix calcinv(matrix m1, matrix m2)
{
    matrix inv;
    matrix m3;
    inv.name = "INVERSE";
    int i, j, menu, det = 0;
    cout << "Enter 1 for Inverse of Matrix 1\n"
            "Enter 2 for Inverse of Matrix 2\n";
                
    cin >> menu;
    switch (menu)
    {
        case 1:
            /*finding the determinant for matrix 1*/
            det = m1.x[0][0]*m1.x[1][1]-m1.x[0][1]*m1.x[1][0];

            /* swaping the positions of element 0 and element 3*/
            /*and putting negatives in front element 1 and element 2 of matrix 1*/
            /*and initilizing the the values of element 0, 1, 2, 3 of matrix 1*/
            /*to element 3, 1, 2, 0 of matrix m3 respectively*/
            m3.x[0][0]=m1.x[1][1];
            m3.x[0][1]=-m1.x[0][1];
            m3.x[1][0]=-m1.x[1][0];
            m3.x[1][1]=m1.x[0][0];

            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            {
                inv.x[i][j] = m3.x[i][j] / det;
            }
        break;
        case 2:
            /*finding the determinant for matrix 1*/
            det = m2.x[0][0]*m2.x[1][1]-m2.x[0][1]*m2.x[1][0];

            /* swaping the positions of element 0 and element 3*/
            /*and putting negatives in front element 1 and element 2 of matrix 2*/
            /*and initilizing the the values of element 0, 1, 2, 3 of matrix 2*/
            /*to element 3, 1, 2, 0 of matrix m3 respectively*/
            m3.x[0][0]=m2.x[1][1];
            m3.x[0][1]=-m2.x[0][1];
            m3.x[1][0]=-m2.x[1][0];
            m3.x[1][1]=m2.x[0][0];

            for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
            {
                inv.x[i][j] = m3.x[i][j] / det;
            }
        break;
        default:
        cout << "invalid\n";
        break;
    }
return inv;
}

void print_matrix(matrix m1, matrix m2, matrix endMatrix)
{
    int i, j;
    /*printing the the name and the elements for the user entered first matrix*/
    cout << endl << m1.name << " is: " << endl;
    for(i = 0; i < 2; ++i)
    for(j = 0; j < 2; ++j)
    {
        cout << m1.x[i][j] << "  ";
        if(j == 2 - 1)
        cout << endl;
    }

    /*printing the the name and the elements for the user entered second matrix*/
    cout << endl << m2.name << " is: " << endl;
    for(i = 0; i < 2; ++i)
    for(j = 0; j < 2; ++j)
    {
        cout << m2.x[i][j] << "  ";
        if(j == 2 - 1)
        cout << endl;
    }

    /*printing the the name and the elements for the resulting matrix*/
    cout << endl << "End Matrix is: " << endl;
    cout << endMatrix.name << endl;
    for(i = 0; i < 2; ++i)
    for(j = 0; j < 2; ++j)
    {
        cout << endMatrix.x[i][j] << "  ";
        if(j == 2 - 1)
        cout << endl;
    }
}