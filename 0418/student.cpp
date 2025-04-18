#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
        string title;
        string author;
        string isbn;
        int year;
        int *p ;
    public:
    Book();
    Book(string _title, string _author, string _isbn, int _year);
    Book(const Book &ref);
    virtual ~Book();
    virtual void displayInfo();
    string getTitle(){return title;}
    string getAuthor(){return author;}
    string getIsbn(){return isbn;}
    int getYear(){return year;}

    string setTitle(string _title){title = _title;}
    string setAuthor(string _author){author=_author;}
    string setIsbn(string _isbn){isbn=_isbn;}
    int setYear(int _year){year=_year;}

};
Book::Book() : title (""), author(""), isbn(""), year(0){
    
}
Book::Book(string _title, string _author, string _isbn, int _year) 
:title(_title),author(_author),isbn(_isbn),year(_year) {

}
Book::Book(const Book &ref)
:title(ref.title),author(ref.author),isbn(ref.isbn),year(ref.year){

    p = new int[100];
    for(int i =0; i , 100; i++){
        p[i] = ref.p[i];
    }
}
Book::~Book(){

}
void Book:: displayInfo(){
    cout << "제목: " << title << endl;
    cout << "저자: " << author << endl;
    cout << "연도: " << year << endl;
    cout << "isbn: " << isbn << endl;
}
class FuctionBook : public Book{
    private:
    string genr;
    public:
  
        virtual void displayInfo() override;
};

void FuctionBook :: displayInfo(){

}
class TextBook : public Book{
    private:
    string liter;
    string education;
    public:
        virtual void displayInfo()override;

};
void TextBook :: displayInfo(){

}
int main(){
    Book *p = new FuctionBook;
    p->setTitle("토끼");
    p->setAuthor("권민주");
    p->setIsbn("출판사");
    p->setYear(2029);

    p-> displayInfo();
    delete p;

    p = new TextBook;
    p -> displayInfo();
    delete p;

    return 0;
}