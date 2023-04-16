// #include <string>
// #include <variant>
// using namespace std;
// Namespace for use in this application
namespace stat
{
    enum Datatype
    {
        str = 0,
        flt = 1
    };
    class Column // Class for column datastructure that stores 'float' values
    {
    public:
        Column(string columnName, Datatype type);
        ~Column();
        string getValueAt(unsigned int rowNo);             // gets value at row number 'rowNo'
        void setValueAt(unsigned int rowNo, float value); // sets the value of row at 'rowNo' to float value of 'value'
        string getHeader();
        // float getMin();                                   // finds the minimum value in the column and returns it
        // float getMax();                                   // finds the maxmimum value in the column and returns it
        // float getMedian();                                // finds the median value of the values in the column
        // float getMean();                                  // finds the mean of the values in the column
        // float getVariance();                              // finds the variance of the values in the column
        // float getStdDev();                                // Finds the value of standard deviation of the values in the column

    private:
        string header;
        vector<string> rows;
        Datatype type;
    };

    // Class declaration for Table
    class Table
    {
    private:
        unsigned int columns, rows;
        vector<Column> data;
        string getRawValueAt(unsigned int x, unsigned int y); // gets string representation of value at column x, row y
        vector<pair<string, int>> columnIndex;

    public:
        Table(unsigned int columns, unsigned int rows);
        ~Table();
        void addNewNumColumn(string header); // Creates new column with header 'header' and appends it to the list of columns
        void removeColumn(string header);    // Removes column with header 'header'
        void insertNumberIntoColumn(string header, unsigned int rowNo, string val);
        void insertStringIntoColumn(string header, unsigned int rowNo, string value);
        float getNumValueAt(string header, unsigned int rowNo);
        string getStrValueAt(string header, unsigned int rowNo); 
        int getColumnIndexFromHeader(string header);
        void displayTable();
    };

}
