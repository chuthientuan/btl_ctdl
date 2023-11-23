#include<bits/stdc++.h>
using namespace std;
class Customer{
	public:
		string fullname;
		string phone_number;
		int customer_code;
		Customer(string fullname, string phone_number, int customer_code){
			this->fullname=fullname;
			this->phone_number=phone_number;
			this->customer_code=customer_code;
		}
		Customer(){
		}
		void input(){
			cout<<"Nhap ho ten: ";
		     getline(cin,fullname);
               cout<<"Nhap so dien thoai: ";
		     getline(cin,phone_number);
		     cout<<"Nhap ma khach hang: ";
			cin>>customer_code;
		}
		void show(){
			cout<<"Ho va ten: "<<fullname<<endl;
			cout<<"So dien thoai: "<<phone_number<<endl;
			cout<<"Ma khach hang: "<<customer_code<<endl;
			cout<<endl;
		}
		string getPhone(){
			return phone_number;
		}
};
class CustomerManager{
	private:
		//Thuat toan quicksort theo ma KH
		int partitionCode(int l,int r){
			int key=v[r].customer_code;     //Dat phan tu cuoi cung lam chot
			int left=l-1;
			for(int right=l;right<=r-1;right++){
				if(v[right].customer_code<key){
					left++;
					swap(v[left],v[right]);
				}
			}
			swap(v[left+1],v[r]);
			return (left+1);
		}
		void quickSort(int l,int r){
			if(l<r){
				int p=partitionCode(l,r);
				quickSort(l,p-1);
				quickSort(p+1,r);
			}
		}
		//Thuat toan quicksort theo ho ten KH
		int partitionName(int l,int r){
			string key=v[r].fullname;     //Dat phan tu cuoi cung lam chot
			int left=l-1;
			for(int right=l;right<=r-1;right++){
				if(v[right].fullname<key){
					left++;
					swap(v[left],v[right]);
				}
			}
			swap(v[left+1],v[r]);
			return (left+1);
		}
		void quicksort(int l,int r){
			if(l<r){
				int p=partitionName(l,r);
				quicksort(l,p-1);
				quicksort(p+1,r);
			}
		}
	public:
		vector<Customer>v;
		//Nhap them thong tin KH
		void add(){
			Customer cus;
			cus.input();
			v.push_back(cus);
		}
		//Xoa thong tin mot khach hang
		void remove(){
			string phone;
			bool deleted = false;
			cout<<"Nhap so dien thoai can xoa: ";
			getline(cin,phone);
			vector<Customer>::iterator it;
			for(it=v.begin();it!=v.end();++it){
				if(it->getPhone()==phone){
					v.erase(it);
					deleted = true;
					break;
				}
			}
			if(deleted) cout<<"Lien he voi so dien thoai: "<<phone<<" da duoc xoa."<<endl;
            	else cout<<"Khong tim thay lien he voi so dien thoai: "<<phone<<endl;
		}
		//Chinh sua thong tin khach hang
		void edit(){
			int customers_code;
			string new_fullname,new_phone_number;
			cout<<"Nhap ma khach hang can chinh sua: ";
			cin>>customers_code;
			cin.ignore(256, '\n');
			bool edited = false;
			for(int i=0;i<v.size();i++){
				if(v[i].customer_code==customers_code){
					cout<<"Nhap ho ten moi: ";
					getline(cin,new_fullname);
					cout<<"Nhap so dien thoai moi: ";
					getline(cin,new_phone_number);
					v[i].fullname=new_fullname;
					v[i].phone_number=new_phone_number;
					edited=true;
					cout<<"Thong tin da duoc chinh sua."<<endl;
					break;
				}
			}
			if(!edited){
        			cout <<"Khong tim thay khach hang voi ma: "<<customers_code<<endl;
    			}
		}
		//Sap xep danh sach KH theo ma KH
		void sortbyCustomerCode(){
			quickSort(0,v.size()-1);
			cout<<"Danh sach khach hang sau khi sap xep theo ma khach hang: "<<endl;
        		display();
		}
		//Sap xep danh sach KH theo ho ten
		void sortbyFullname(){
			quicksort(0,v.size()-1);
			cout<<"Danh sach khach hang sau khi sap xep theo ho ten:"<<endl;
        		display();
		}
		//Hien thi danh sach KH
		void display(){
			cout<<"Danh sach khach hang hien co:"<<endl;
			for(int i=0;i<v.size();i++){
				v[i].show();
			}
		}
		//Luu thong tin khach hang vao file
		void savetofile(){
			ofstream file("customers.txt");
			if(!file.is_open()) {
        			cout<<"Khong the mo tap tin de viet."<<endl;
        			return;
    			}
			for(int i = 0; i < v.size(); i++) {
				file<<"Ho va ten: ";
        			file<<v[i].fullname<<endl;
        			file<<"So dien thoai: ";
        			file<<v[i].phone_number<<endl;
        			file<<"Ma khach hang: ";
        			file<<v[i].customer_code<<endl;
        			file<<endl;
    			}
   			file.close();
    			cout<<"Da luu du lieu vao 'customers.txt' thanh cong."<<endl;
		}
};
int main(){
	CustomerManager customers;
	customers.v.push_back(Customer("Tuan","96",24));
    	customers.v.push_back(Customer("Linh","95",25));
    	customers.v.push_back(Customer("Son","99",9));
	int choice;
	while(true){
		cout<<"\tDanh sach thao tac:"<<endl;
		cout<<"1. Nhap them thong tin cac khach hang."<<endl;
		cout<<"2. Xoa thong tin khach hang."<<endl;
		cout<<"3. Sua doi thong tin ho ten, so dien thoai cua mot khach hang."<<endl;
		cout<<"4. Sap xep danh sach khach hang theo ma khach hang."<<endl;
		cout<<"5. Sap xep danh sach khach hang theo ho ten."<<endl;
		cout<<"6. Danh sach khach hang hien co."<<endl;
		cout<<"7. Thoat."<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>choice;
		cin.ignore(256,'\n');
		switch(choice){
			case 1:{
				customers.add();
				char d;
				while(1){
					cout<<endl;
					cout<<"Nhap Y de nhap tiep. Nhap N de ket thuc."<<endl;
					cout<<"Ban co nhap nua khong: ";
					cin>>d;
					cin.ignore(256,'\n');
					if(d=='Y'){
						customers.add();
					}
					else if(d=='N'){
						break;
					}
					else{
						cout<<"Lua chon khong hop le. Vui long thu lai!";
					}
				}
				break;
			}
			case 2:{
				customers.remove();
				break;
			}
			case 3:{
				customers.edit();
				break;
			}
			case 4:{
				customers.sortbyCustomerCode();
				break;
			}
			case 5:{
				customers.sortbyFullname();
				break;
			}
			case 6:{
				customers.display();
				break;
			}
			case 7:{
				return 0;
				break;
			}
			default: {
                cout<<"Lua chon khong hop le. Vui long thu lai!"<<endl;
                break;
            	}
		}
		customers.savetofile();
	}
}
