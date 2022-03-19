#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<iostream>
#include<cstring>

//#include"img_processing.h"

using namespace std;
using namespace cv;

// img data processing
class img_data{
    private:
        Mat img;
        string path = NULL;
    public:
        int operator >> (string path);
        Mat get_img();
        void Display ();
        void save_img();
        string get_img_path();
};

int img_data::operator >> (string path){
    img_data::path = path;
    img_data::img = imread(img_data::path,IMREAD_COLOR); 
   
    if(img.empty()){
        std::cout << "Could not read the image: " << path << std::endl;
        return 1;
    }
    
    return 0;
}

Mat img_data::get_img(){
    return img_data::img;
}
void img_data::Display(){
    imshow("Display Window",img_data::img);
    waitKey(0);
}
void img_data::save_img(){
    //tips : imwrite("data_name.png", img);
}         
string img_data::get_img_path(){
    return img_data::path;
}

// link_list node setting

typedef struct DATA{
    char name[50];
    float score;
    char number[50];
    class img_data stu_img;

}tDATA;

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    tDATA* data;
}tNode;

typedef struct NodeHead{
    tNode* front;
    tNode* tail;
    int count;
}tNodeHead;

// Linked list function
class Linked_list{
    private:
        tNodeHead* link_list_head = (tNodeHead*) malloc(sizeof(tNodeHead));
    public:
        Linked_list(){
            this->link_list_init(link_list_head);
        }
        void link_list_init(tNodeHead* link_list_head);
        void add_node(tDATA* stu_data);
        void print_link_list();
};

void Linked_list::link_list_init(tNodeHead* link_list_head){
            this->link_list_head->front  = NULL;
            this->link_list_head->tail  = NULL;
            this->link_list_head->count = 0;
}

void Linked_list::print_link_list(){
    tNode* node = this->link_list_head->front;
    
    while(node != NULL){
        cout << endl << "Student's name : " << node->data->name << endl;
        cout << "Score : " << node->data->score << endl;
        node = node->next;
    }
    cout << endl;

}

void Linked_list::add_node(tDATA* stu_data){
    tNode* new_node = (tNode*) malloc(sizeof(tNodeHead));
    new_node->data = (tDATA*) malloc(sizeof(tDATA));
    strcpy(new_node->data->name,stu_data->name);
    new_node->data->score = stu_data->score;


    if(this->link_list_head->count == 0){
        new_node->next = NULL;
        new_node->prev = NULL;
        this->link_list_head->front = new_node;

    }
    else{

        tNode* node_p = this->link_list_head->front;
        new_node->next = node_p;
        node_p->prev = new_node;
        this->link_list_head->front = new_node;
        this->link_list_head->tail = node_p;
    }
    this->link_list_head->count++;
} 


int menu(){
    int choose;
    cout << "(0)Exit" << endl;
    cout << "(1)Add student information" << endl;           
    cout << "(2)Query student information" << endl;     
    cout << "Please enter a number : " ;
    cin >> choose;
    return choose;
              
}

int main(){
    Linked_list* data_list = new Linked_list;
    tDATA* stu_data = (tDATA*)malloc(sizeof(tDATA));
    
    int choose = 1;

    while(1){
        choose = menu();
        if(choose == 0){
            break;
        }
//      add data
        if(choose == 1){
            
            cout << "Please enter student's name : "; 
            cin  >> stu_data->name;
            cout << "Please enter "<< stu_data->name << "\'s ID number :";
            cin  >> stu_data->number;
            cout << "Please enter " << stu_data->name << "\'s score : ";
            cin  >> stu_data->score;

            string temp_path;
            cout << "Please enter image path : ";
            cin  >> temp_path;
            stu_data->stu_img >> temp_path;
            
            data_list->add_node(stu_data);
            data_list->print_link_list();
        }
//      query data
        else if(choose == 2){
            /*====================*/
        }
//      delete data
        else if(choose == 3){

        }
        else{
            cout << "No such choose!" << endl;
        }
    }
    return 0;
}

//=====================   Worker Info ======================
// Worker : WeiXuan You
// Date   : 3/20/2022
// mail   : you20610@gmail.com
