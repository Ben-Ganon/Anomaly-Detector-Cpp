#include <iostream>
#include "timeseries.cpp"
bool wrong(float val, float expected) {
    return val < expected - 0.001 || val > expected + 0.001;
}
int main() {

    //sagiv's path
    TimeSeries *a = new TimeSeries("C:\\Users\\sagiv\\Desktop\\Ex1Task2\\csvTest.csv");
    cout<<"-------------checks printTable-------------"<<endl;
    a->printTable();
//    vector<float> b = a->getRow(2);
//
//    for (float f: b) {
//        cout << f << endl;
//        cout << "hi";
//    }
    //checks getCell
    cout<<"-------------checks getCell-------------"<<endl;
    if(a->getCell(2,2)!=3)
        cout<<"need to be 3"<<endl;
    if(wrong(a->getCell(1,1),63.2))
        cout<<"need to be 63.2"<<endl;
    //checks setCell
    cout<<"-------------checks setCell-------------"<<endl;
    a->setCell(1,1,0);
    if(wrong(a->getCell(1,1),0))
        cout<<"(1,1) need to be 0"<<endl;
    //checks for addRow
    cout<<"-------------checks addRow-------------"<<endl;
    vector<float> values = {0,1,69};
    a->addRow(values);
    a->printTable();
    //checks for getColumn
    cout<<"-------------checks getColumn-------------"<<endl;
    values = a->getColumn(1);
    for (float i: values)
        std::cout << i << ' ';
    cout<<endl;
    //checks for getRow
    cout<<"-------------checks getRow-------------"<<endl;
    values = a->getRow(1);
    for (float i: values)
        std::cout << i << ' ';
    cout<<endl;

    delete a;
    return 0;
}