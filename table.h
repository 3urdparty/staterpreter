#include<string>
using namespace std;
// Namespace for use in this application
namespace stat
{
    // Class declaration for Table
    class Table
    {
    private:
        unsigned int columns, rows;
        vector<Column>
        
        string getRawValue(unsigned int x, unsigned int y); //gets string representation of value at column x, row y

    public:
        Table(unsigned int columns, unsigned int rows);
        ~Table();
        void addNewColumn(string header); //Creates new column with header 'header' and appends it to the list of columns
        void removeColumn(string header); //Removes column with header 'header'
        void insertNumberIntoColumn(unsigned int value);
        void insertStringIntoColumn(string value);
        
    };


    class BaseColumn{}; //Base column class
    class NumColumn //Class for column datastructure that stores 'float' values
    { 
        public:
            NumColumn(string columnName) :header{columnName} {};
            float getValueAt(unsigned int rowNo); //gets value at row number 'rowNo'
            void setValueAt(unsigned int rowNo, float value); //sets the value of row at 'rowNo' to float value of 'value'
            float getMin(); //finds the minimum value in the column and returns it
            float getMax(); //finds the maxmimum value in the column and returns it
            float getMedian(); //finds the median value of the values in the column
            float getMean(); //finds the mean of the values in the column
            float getVariance(); //finds the variance of the values in the column
            float getStdDev(); //Finds the value of standard deviation of the values in the column

        private:
            string header;
            vector<float> rows;
    };
}
