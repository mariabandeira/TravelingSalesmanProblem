#ifndef DATA_H
#define DATA_H

class Data{

    private:
        static Data * instance;
        Data();

    public:

        int n;
        double ** matrizAdj;

        static Data & getInstance();

        static void read(int , char**);
};
extern void readData( int , char** , int* , double *** );
#endif // DATA_H
