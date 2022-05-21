/* TMF1434 Data Structure and Algorithm
Assignment - The Computer Shop
Lecturer: Dr Wang Hui Hui

Written by:

1. Muhamad Zulhilmi Bin Zainal Abidin (78201)
2. Ahmad Syafiq Bin Salleh (78668) 

We're using range-based for loop in our program so language standard (-std) needs to be set as ISO C++ 11 in order to compile and run this program*/

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;
#define MAX_SIZE 10
#define STOCKFILE "Stock.txt"

class Product
{
private:
	string Brand;
	string Model;
	double Price;
	int Quantity;
	string Color;
	string Category;
public:

	//Getter
	string getBrand()
	{
		return Brand;
	}

	string getModel()
	{
		return Model;
	}

	double getPrice()
	{
		return Price;
	}

	double getQuantity()
	{
		return Quantity;
	}

	string getColor()
	{
		return Color;
	}

	string getCategory()
	{
		return Category;
	}

	//Setter
	void setBrand(string brand)
	{
		Brand = brand;
	}

	void setModel(string model)
	{
		Model = model;
	}

	void setPrice(double price)
	{
		Price = price;
	}

	void setQuantity(int quantity)
	{
		Quantity = quantity;
	}

	void setColor(string color)
	{
		Color = color;
	}

	void setCategory(string category)
	{
		Category = category;
	}

	//Constructor

	Product(int quantity, string model, double price, string color, string category, string brand)
	{
		Model = model;
		Price = price;
		Quantity = quantity;
		Color = color;
		Category = category;
		Brand = brand;
	}

	virtual void header()
	{
		cout << "Header";
	};
};

class Computer : public Product
{
private:
	string Type;
	string ScreenSize;
	string OS;
	string CPU;
	string ClockSpeed;
	string Resolution;
public:
	//Getter

	string getType()
	{
		return Type;
	}

	string getScreenSize()
	{
		return ScreenSize;
	}

	string getOS()
	{
		return OS;
	}

	string getCPU()
	{
		return CPU;
	}

	string getClockSpeed()
	{
		return ClockSpeed;
	}

	string getResolution()
	{
		return Resolution;
	}

	//Setter

	void setType(string type)
	{
		Type = type;
	}

	void setScreenSize(string screenSize)
	{
		ScreenSize = screenSize;
	}

	void setOS(string os)
	{
		OS = os;
	}

	void setCPU(string processer)
	{
		CPU = processer;
	}

	void setClockSpeed(string clockSpeed)
	{
		ClockSpeed = clockSpeed;
	}

	void setResolution(string resolution)
	{
		Resolution = resolution;
	}

	//Constructor
	Computer() : Product(0, "0", 0, "0", "0", "0") {}

	Computer(string brand, string type, string screenSize, string os, string processer, string clockSpeed, string resolution, string model, double price, int quantity, string color, string category)
		:Product(quantity, model, price, color, category, brand)
	{
		Type = type;
		ScreenSize = screenSize;
		OS = os;
		CPU = processer;
		ClockSpeed = clockSpeed;
		Resolution = resolution;
	}

	Computer readFComputer(ifstream& file)
	{
		Computer c;

		string tempStr;
		int tempInt;
		double tempDouble;

		c.setCategory("Computer");

		getline(file, tempStr);
		c.setType(tempStr);

		getline(file, tempStr);
		c.setBrand(tempStr);

		getline(file, tempStr);
		c.setModel(tempStr);

		getline(file, tempStr);
		c.setScreenSize(tempStr);

		getline(file, tempStr);
		c.setOS(tempStr);

		getline(file, tempStr);
		c.setCPU(tempStr);

		getline(file, tempStr);
		c.setClockSpeed(tempStr);

		getline(file, tempStr);
		c.setColor(tempStr);

		getline(file, tempStr);
		c.setResolution(tempStr);

		file >> tempDouble;
		c.setPrice(tempDouble);

		file >> tempInt;
		c.setQuantity(tempInt);

		return c;
	}

	void header()
	{
		cout << "\n";
		cout << " " << "========================================================================================================================================================================================================\n";
		cout << " " << setw(70) << "Computer" << endl;
		cout << " " << "========================================================================================================================================================================================================\n";
		cout << " " << setw(3) << "NO";
		cout << " " << setw(9) << "Type";
		cout << " " << setw(12) << "Brand";
		cout << " " << setw(20) << "Model";
		cout << " " << setw(20) << "Screen Size";
		cout << " " << setw(20) << "OS";
		cout << " " << setw(30) << "CPU";
		cout << " " << setw(20) << "ClockSpeed";
		cout << " " << setw(15) << "Color";
		cout << " " << setw(20) << "Resolution";
		cout << " " << setw(10) << "Price(RM)";
		cout << " " << setw(10) << "Quantity" << endl;
		cout << " --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
};

class Accessories : public Product
{
private:
	string Type;
	string ConnectType_A;
	string Dimension;
public:

	//Getter
	string getType()
	{
		return Type;
	}

	string getConnectType_A()
	{
		return ConnectType_A;
	}

	string getDimension()
	{
		return Dimension;
	}

	//Setter
	void setType(string type)
	{
		Type = type;
	}

	void setConnectType_A(string connectType)
	{
		ConnectType_A = connectType;
	}

	void setDimension(string dimension)
	{
		Dimension = dimension;
	}

	//Constructor
	Accessories() : Product(0, "0", 0, "0", "0", "0") {};

	Accessories(string connectType, string dimension, string model, double price, int quantity, string color, string category, string brand, string type)
		:Product(quantity, model, price, color, category, brand)
	{
		ConnectType_A = connectType;
		Dimension = dimension;
	}

	Accessories readFAccessories(ifstream& file)
	{
		Accessories a;

		string tempStr;
		int tempInt;
		double tempDouble;

		a.setCategory("Accessories");

		getline(file, tempStr);
		a.setType(tempStr);

		getline(file, tempStr);
		a.setBrand(tempStr);

		getline(file, tempStr);
		a.setModel(tempStr);

		getline(file, tempStr);
		a.setConnectType_A(tempStr);

		getline(file, tempStr);
		a.setDimension(tempStr);

		getline(file, tempStr);
		a.setColor(tempStr);

		file >> tempDouble;
		a.setPrice(tempDouble);

		file >> tempInt;
		a.setQuantity(tempInt);

		return a;
	}

	void header()
	{
		cout << "\n";
		cout << " " << "==========================================================================================================================\n";
		cout << " " << setw(70) << "Accessories" << endl;
		cout << " " << "==========================================================================================================================\n";
		cout << " " << setw(3) << "NO";
		cout << " " << setw(9) << "Type";
		cout << " " << setw(12) << "Brand";
		cout << " " << setw(20) << "Model";
		cout << " " << setw(20) << "Connect Type";
		cout << " " << setw(15) << "Dimensions";
		cout << " " << setw(15) << "Color";
		cout << " " << setw(10) << "Price(RM)";
		cout << " " << setw(10) << "Quantity" << endl;
		cout << " " << "--------------------------------------------------------------------------------------------------------------------------\n";
	}
};

class Printer : public Product
{
private:
	string PrintType;
	string ConnectType_P;
	string Compatible;
	string SheetSize;
	string OutputType;
public:
	//Getter
	string getPrintType()
	{
		return PrintType;
	}

	string getConnectType_P()
	{
		return ConnectType_P;
	}

	string getCompatible()
	{
		return Compatible;
	}

	string getSheetSize()
	{
		return SheetSize;
	}

	string getOutputType()
	{
		return OutputType;
	}

	//Setter
	void setPrintType(string printType)
	{
		PrintType = printType;
	}

	void setConnectType_P(string connectType)
	{
		ConnectType_P = connectType;
	}

	void setCompatible(string compatible)
	{
		Compatible = compatible;
	}

	void setSheetSize(string sheetSize)
	{
		SheetSize = sheetSize;
	}

	void setOutputType(string outputType)
	{
		OutputType = outputType;
	}

	//Constructor
	Printer() : Product(0, "0", 0, "0", "0", "0") {};

	Printer(string printType, string connectType, string compatible, string sheetSize, string outputType, string model, double price, int quantity, string color, string category, string brand)
		:Product(quantity, model, price, color, category, brand)
	{
		PrintType = printType;
		ConnectType_P = connectType;
		Compatible = compatible;
		SheetSize = sheetSize;
		OutputType = outputType;
	}

	Printer readFPrinter(ifstream& file)
	{
		Printer p;

		string tempStr;
		int tempInt;
		double tempDouble;

		p.setCategory("Printer");

		getline(file, tempStr);
		p.setBrand(tempStr);

		getline(file, tempStr);
		p.setModel(tempStr);

		getline(file, tempStr);
		p.setPrintType(tempStr);

		getline(file, tempStr);
		p.setConnectType_P(tempStr);

		getline(file, tempStr);
		p.setCompatible(tempStr);

		getline(file, tempStr);
		p.setSheetSize(tempStr);

		getline(file, tempStr);
		p.setColor(tempStr);

		getline(file, tempStr);
		p.setOutputType(tempStr);

		file >> tempDouble;
		p.setPrice(tempDouble);

		file >> tempInt;
		p.setQuantity(tempInt);

		return p;
	}

	void header()
	{
		cout << "\n";
		cout << " " << "==============================================================================================================================================================================================\n";
		cout << " " << setw(70) << "Printer" << endl;
		cout << " " << "==============================================================================================================================================================================================\n";
		cout << " " << setw(3) << "NO";
		cout << " " << setw(12) << "Brand";
		cout << " " << setw(20) << "Model";
		cout << " " << setw(20) << "Print Type";
		cout << " " << setw(20) << "Connect Type";
		cout << " " << setw(30) << "Compatible Device";
		cout << " " << setw(20) << "Sheet Size";
		cout << " " << setw(15) << "Color";
		cout << " " << setw(20) << "Printer Output";
		cout << " " << setw(10) << "Price(RM)";
		cout << " " << setw(10) << "Quantity" << endl;
		cout << " " << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
};

class Function
{
public:
	void displayLine(char type, int total)
	{
		cout << " ";
		for (int i = 0; i < total; i++)
		{
			cout << type;
		}
		cout << " \n";
	}
	void addProducts()
	{
		int option = 0;
		do
		{
			system("cls");
			cout << "   Add Products\n";
			cout << "\n  Computer     - 1";
			cout << "\n  Printer      - 2";
			cout << "\n  Accessories  - 3";

			cout << "\n\n Select Categories > ";
			cin >> option;

			//Open file
			ofstream file;
			file.open(STOCKFILE, ios::app);

			if (option == 1)
			{
				Computer p = Computer("0", "0", "0", "0", "0", "0", "0", "0", 0, 0, "0", "0");
				p.setCategory("Computer");

				option = 0;
				while (option > 3 || option <= 0)
				{
					cout << "\n  Desktop      - 1";
					cout << "\n  Laptop       - 2";
					cout << "\n  Monitor      - 3";

					cout << "\n\n Select Type > ";
					cin >> option;
					if (option == 1)
					{
						p.setType("Desktop");
					}
					else if (option == 2)
					{
						p.setType("Laptop");
					}
					else if (option == 3)
					{
						p.setType("Monitor");
					}
				}

				string brand;
				cout << " Enter Brand > ";
				cin.ignore();
				getline(cin, brand);
				p.setBrand(brand);

				cout << " Enter Product Model > ";
				string model;
				getline(cin, model);
				p.setModel(model);

				cout << " Enter Screen Size > ";
				string screenSize;
				getline(cin, screenSize);
				p.setScreenSize(screenSize);

				cout << " Enter Operating System Type > ";
				string os;
				getline(cin, os);
				p.setOS(os);

				cout << " Enter CPU/Processer Model > ";
				string processer;
				getline(cin, processer);
				p.setCPU(processer);

				cout << " Enter Clock Speed > ";
				string clockSpeed;
				getline(cin, clockSpeed);
				p.setClockSpeed(clockSpeed);

				cout << " Enter Color > ";
				string color;
				getline(cin, color);
				p.setColor(color);

				cout << " Enter Resolution eg(1920x1080) > ";
				string resolution;
				getline(cin, resolution);
				p.setResolution(resolution);

				cout << " Enter Price > RM";
				double price;
				cin >> price;
				p.setPrice(price);

				cout << " Enter Quantity > ";
				int quantity;
				cin >> quantity;
				p.setQuantity(quantity);

				file << p.getCategory() << endl << p.getType() << endl << p.getBrand() << endl << p.getModel() << endl << p.getScreenSize() << endl << p.getOS() << endl << p.getCPU() << endl << p.getClockSpeed() << endl << p.getColor() << endl << p.getResolution() << endl << p.getPrice() << endl << p.getQuantity() << endl;
			}
			else if (option == 2)
			{
				Printer p = Printer("0", "0", "0", "0", "0", "0", 0, 0, "0", "0", "0");
				p.setCategory("Printer");

				string brand;
				cout << " Enter Brand > ";
				cin.ignore();
				getline(cin, brand);
				p.setBrand(brand);

				cout << " Enter Product Model > ";
				string model;
				getline(cin, model);
				p.setModel(model);

				cout << " Enter Printing Technology > ";
				string printType;
				getline(cin, printType);
				p.setPrintType(printType);

				cout << " Enter Connectivity Technology > ";
				string connectType;
				getline(cin, connectType);
				p.setConnectType_P(connectType);

				cout << " Enter Compatible Devices > ";
				string compatible;
				getline(cin, compatible);
				p.setCompatible(compatible);

				cout << " Enter Sheet Size > ";
				string sheetSize;
				getline(cin, sheetSize);
				p.setSheetSize(sheetSize);

				cout << " Enter Color > ";
				string color;
				getline(cin, color);
				p.setColor(color);

				cout << " Enter Output Type > ";
				string outputType;
				getline(cin, outputType);
				p.setOutputType(outputType);

				cout << " Enter Price > RM";
				double price;
				cin >> price;
				p.setPrice(price);

				cout << " Enter Quantity > ";
				int quantity;
				cin >> quantity;
				p.setQuantity(quantity);

				file << p.getCategory() << endl << p.getBrand() << endl << p.getModel() << endl << p.getPrintType() << endl << p.getConnectType_P() << endl << p.getCompatible() << endl << p.getSheetSize() << endl << p.getColor() << endl << p.getOutputType() << endl << p.getPrice() << endl << p.getQuantity() << endl;
			}
			else if (option == 3)
			{
				Accessories p = Accessories("0", "0", "0", 0, 0, "0", "0", "0", "0");
				p.setCategory("Accessories");

				option = 0;
				while (option > 3 || option <= 0)
				{
					system("cls");
					cout << "   Add Products\n";
					cout << "\n KeyBoard      - 1";
					cout << "\n Mouse         - 2";
					cout << "\n Others        - 3";
					cout << "\n\n Select Type > ";
					cin >> option;
					if (option == 1)
					{
						p.setType("KeyBoard");
					}
					else if (option == 2)
					{
						p.setType("Mouse");
					}
					else if (option == 3)
					{
						p.setType("Others");
					}
				}

				string brand;
				cout << " Enter Brand > ";
				cin.ignore();
				getline(cin, brand);
				p.setBrand(brand);

				cout << " Enter Product Model > ";
				string model;
				getline(cin, model);
				p.setModel(model);

				cout << " Enter Connectivity Technology > ";
				string connectType;
				getline(cin, connectType);
				p.setConnectType_A(connectType);

				cout << " Enter Dimensions > ";
				string dimension;
				getline(cin, dimension);
				p.setDimension(dimension);

				cout << " Enter Color > ";
				string color;
				getline(cin, color);
				p.setColor(color);

				cout << " Enter Price > RM";
				double price;
				cin >> price;
				p.setPrice(price);

				cout << " Enter Quantity > ";
				int quantity;
				cin >> quantity;
				p.setQuantity(quantity);

				file << p.getCategory() << endl << p.getType() << endl << p.getBrand() << endl << p.getModel() << endl << p.getConnectType_A() << endl << p.getDimension() << endl << p.getColor() << endl << p.getPrice() << endl << p.getQuantity() << endl;
			}
			file.close();
			option = 1;
		} while (option > 3 || option <= 0);

	}
	void viewAll()
	{
		ifstream file;
		file.open(STOCKFILE);
		int computer_Total = 0, printer_Total = 0, accessories_Total = 0;
		Computer c[MAX_SIZE];
		Printer p[MAX_SIZE];
		Accessories a[MAX_SIZE];
		while (!file.eof())
		{
			string category;
			getline(file, category);
			if (category == "Computer")
			{
				c[computer_Total] = c[computer_Total].readFComputer(file);
				computer_Total++;
			}
			else if (category == "Printer")
			{
				p[printer_Total] = p[printer_Total].readFPrinter(file);
				printer_Total++;
			}
			else if (category == "Accessories")
			{
				a[accessories_Total] = a[accessories_Total].readFAccessories(file);
				accessories_Total++;
			}
		}

		if (computer_Total == 0 && printer_Total == 0 && accessories_Total == 0)
		{
			cout << "\n" << setw(20) << "No Stocks Found\n";
		}
		else
		{
			cout << "\n  View All\n";
			if (computer_Total > 0)
			{
				c->header();
				for (int k = 0; k < computer_Total; k++)
				{
					displayComputer(c[k], k + 1);
				}
				cout << " --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << endl;
			}

			if (printer_Total > 0)
			{
				p->header();
				for (int k = 0; k < printer_Total; k++)
				{
					displayPrinter(p[k], k + 1);
				}
				cout << " " << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << endl;
			}

			if (accessories_Total > 0)
			{
				a->header();
				for (int k = 0; k < accessories_Total; k++)
				{
					displayAccessories(a[k], k + 1);
				}
				cout << " --------------------------------------------------------------------------------------------------------------------------\n";
				cout << endl;
			}
			file.close();
		}
		cout << "  Press Any Key To Go Back...";
		getch();
	}
	void displayComputer(Computer p, int no)
	{
		cout << " " << setw(3) << no;
		cout << " " << setw(9) << p.getType();
		cout << " " << setw(12) << p.getBrand();
		cout << " " << setw(20) << p.getModel();
		cout << " " << setw(20) << p.getScreenSize();
		cout << " " << setw(20) << p.getOS();
		cout << " " << setw(30) << p.getCPU();
		cout << " " << setw(20) << p.getClockSpeed();
		cout << " " << setw(15) << p.getColor();
		cout << " " << setw(20) << p.getResolution();
		cout << " " << setw(10) << p.getPrice();
		cout << " " << setw(10) << p.getQuantity() << endl;
	}
	void displayAccessories(Accessories p, int no)
	{
		cout << " " << setw(3) << no;
		cout << " " << setw(9) << p.getType();
		cout << " " << setw(12) << p.getBrand();
		cout << " " << setw(20) << p.getModel();
		cout << " " << setw(20) << p.getConnectType_A();
		cout << " " << setw(15) << p.getDimension();
		cout << " " << setw(15) << p.getColor();
		cout << " " << setw(10) << p.getPrice();
		cout << " " << setw(10) << p.getQuantity() << endl;
	}
	void displayPrinter(Printer p, int no)
	{
		cout << " " << setw(3) << no;
		cout << " " << setw(12) << p.getBrand();
		cout << " " << setw(20) << p.getModel();
		cout << " " << setw(20) << p.getPrintType();
		cout << " " << setw(20) << p.getConnectType_P();
		cout << " " << setw(30) << p.getCompatible();
		cout << " " << setw(20) << p.getSheetSize();
		cout << " " << setw(15) << p.getColor();
		cout << " " << setw(20) << p.getOutputType();
		cout << " " << setw(10) << p.getPrice();
		cout << " " << setw(10) << p.getQuantity() << endl;
	}
	void searchProducts()
	{
		int option = -1;

		while (option > 3 || option < 0)
		{
			cout << "\n  Search By - \n";
			cout << "  Category  1\n";
			cout << "  Type      2\n";
			cout << "  Model     3\n";
			cout << "  Back      0\n";
			cout << "\n Select Option > ";
			cin >> option;
			system("cls");
		}

		if (option != 0)
		{
			ifstream file;
			file.open(STOCKFILE);
			int computer_Total = 0, printer_Total = 0, accessories_Total = 0;
			Computer c[MAX_SIZE];
			Printer p[MAX_SIZE];
			Accessories a[MAX_SIZE];

			while (!file.eof())
			{
				string category;
				getline(file, category);
				if (category == "Computer")
				{
					c[computer_Total] = c[computer_Total].readFComputer(file);
					computer_Total++;
				}
				else if (category == "Printer")
				{
					p[printer_Total] = p[printer_Total].readFPrinter(file);
					printer_Total++;
				}
				else if (category == "Accessories")
				{
					a[accessories_Total] = a[accessories_Total].readFAccessories(file);
					accessories_Total++;
				}
			}
			file.close();

			if (option == 1)
			{
				option = 0;
				while (option > 3 || option < 1)
				{
					cout << "  Computer      1\n";
					cout << "  Printer       2\n";
					cout << "  Accessories   3\n";
					cout << "\n Select Option > ";
					cin >> option;
					system("cls");
				}
				cout << "\n   Products Found\n";

				if (option == 1)
				{
					if (computer_Total > 0)
					{
						c->header();
						for (int k = 0; k < computer_Total; k++)
						{
							displayComputer(c[k], k + 1);
						}
						cout << " --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
						cout << endl;
					}
					else
					{
						system("cls");
						cout << "\n\n  No Matching Products Found\n";
					}

				}
				else if (option == 2)
				{
					if (printer_Total > 0)
					{
						p->header();
						for (int k = 0; k < printer_Total; k++)
						{
							displayPrinter(p[k], k + 1);
						}
						cout << " " << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
						cout << endl;
					}
					else
					{
						system("cls");
						cout << "\n\n  No Matching Products Found\n";
					}
				}
				else
				{
					if (accessories_Total > 0)
					{
						a->header();
						for (int k = 0; k < accessories_Total; k++)
						{
							displayAccessories(a[k], k + 1);
						}
						cout << " --------------------------------------------------------------------------------------------------------------------------\n";
						cout << endl;
					}
					else
					{
						system("cls");
						cout << "\n\n  No Matching Products Found\n";
					}
				}
			}
			else if (option == 2)
			{
				cout << "\n Enter Type To Search eg(Laptop,Desktop,Keyboard) > ";
				cin.ignore();
				string search;
				getline(cin, search);
				for (auto& g : search) g = toupper(g);

				int found = 0, totalFound = 0;
				cout << "\n   Products Found\n";
				for (int k = 0; k < computer_Total; k++)
				{
					string type = c[k].getType();
					for (auto& g : type) g = toupper(g);
					if (type == search)
					{
						if (found == 0)
						{
							c->header();
						}
						displayComputer(c[k], found + 1);
						found++;
					}
				}
				if (found == 1)
				{
					cout << " --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					totalFound++;
				}
				found = 0;
				for (int k = 0; k < accessories_Total; k++)
				{
					string type = a[k].getType();
					for (auto& g : type) g = toupper(g);
					if (type == search)
					{
						if (found == 0)
						{
							a->header();
						}
						displayAccessories(a[k], found + 1);
						found++;
					}
				}
				if (found == 1)
				{
					cout << " --------------------------------------------------------------------------------------------------------------------------\n";
					totalFound++;
				}

				if (totalFound == 0)
				{
					system("cls");
					cout << "\n\n  No Matching Products Found\n";
				}
			}
			else if (option == 3)
			{
				cout << "\n Enter Model To Search > ";
				cin.ignore();
				string search;
				getline(cin, search);
				for (auto& g : search) g = toupper(g);

				int found = 0, totalFound = 0;
				cout << "\n   Products Found\n";
				for (int k = 0; k < computer_Total; k++)
				{
					string model = c[k].getModel();
					for (auto& g : model) g = toupper(g);
					if (model == search)
					{
						if (found == 0)
						{
							c->header();
						}
						displayComputer(c[k], found + 1);
						found++;
					}
				}
				if (found == 1)
				{
					cout << " --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					totalFound++;
				}
				found = 0;
				for (int k = 0; k < accessories_Total; k++)
				{
					string model = a[k].getModel();
					for (auto& g : model) g = toupper(g);
					if (model == search)
					{
						if (found == 0)
						{
							a->header();
						}
						displayAccessories(a[k], found + 1);
						found++;
					}
				}
				if (found == 1)
				{
					cout << " ------------------------------------------------------------------------------------------------------------------\n";
					totalFound++;
				}
				found = 0;
				for (int k = 0; k < printer_Total; k++)
				{
					string model = p[k].getModel();
					for (auto& g : model) g = toupper(g);
					if (model == search)
					{
						if (found == 0)
						{
							p->header();
						}
						displayPrinter(p[k], found + 1);
						found++;
					}
				}

				if (found == 1)
				{
					cout << " " << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					totalFound++;
				}

				if (totalFound == 0)
				{
					system("cls");
					cout << "\n\n  No Matching Products Found\n";
				}

			}
			cout << "\n  Press Any Key To Go Back...";
			getch();
		}
	}
	void deleteProduct()
	{
		ifstream file;
		file.open(STOCKFILE);
		int computer_Total = 0, printer_Total = 0, accessories_Total = 0;
		Computer c[MAX_SIZE];
		Printer p[MAX_SIZE];
		Accessories a[MAX_SIZE];

		while (!file.eof())
		{
			string category;
			getline(file, category);

			if (category == "Computer")
			{
				c[computer_Total] = c[computer_Total].readFComputer(file);
				computer_Total++;
			}
			else if (category == "Printer")
			{
				p[printer_Total] = p[printer_Total].readFPrinter(file);
				printer_Total++;
			}
			else if (category == "Accessories")
			{
				a[accessories_Total] = a[accessories_Total].readFAccessories(file);
				accessories_Total++;
			}
		}
		file.close();

		cout << "\n Enter Products' Model To Delete > ";
		cin.ignore();
		string search;
		getline(cin, search);
		for (auto& g : search) g = toupper(g);
		system("cls");

		int found = -1;
		int type;

		for (int k = 0; k < computer_Total; k++)
		{
			string model = c[k].getModel();
			for (auto& g : model) g = toupper(g);
			if (model == search)
			{
				if (found == -1)
				{
					c->header();
					displayComputer(c[k], found + 2);
					type = 1;
					found = k;
					break;
				}
			}
		}

		for (int k = 0; k < accessories_Total; k++)
		{
			string model = a[k].getModel();
			for (auto& g : model) g = toupper(g);
			if (model == search)
			{
				if (found == -1)
				{
					a->header();
					displayAccessories(a[k], found + 2);
					type = 2;
					found = k;
					break;
				}
			}
		}

		for (int k = 0; k < printer_Total; k++)
		{
			string model = p[k].getModel();
			for (auto& g : model) g = toupper(g);
			if (model == search)
			{
				if (found == -1)
				{
					p->header();
					displayPrinter(p[k], found + 2);
					type = 3;
					found = k;
					break;
				}
			}
		}

		if (found == -1)
		{
			system("cls");
			cout << "\n\n  No Matching Products Found\n";
		}
		else
		{
			cout << "\n\n  Press 'Y' to confirm\n";
			cout << "  Confirm To Delete The Selected ? > ";
			char confirm;
			cin >> confirm;


			if (confirm == 'y' || confirm == 'Y')
			{
				ofstream file;
				file.open(STOCKFILE);

				for (int l = 0; l < computer_Total; l++)
				{
					if (type == 1)
					{
						if (l != found)
						{
							file << c[l].getCategory() << endl << c[l].getType() << endl << c[l].getBrand() << endl << c[l].getModel() << endl << c[l].getScreenSize() << endl << c[l].getOS() << endl << c[l].getCPU() << endl << c[l].getClockSpeed() << endl << c[l].getColor() << endl << c[l].getResolution() << endl << c[l].getPrice() << endl << c[l].getQuantity() << endl;
						}
					}
					else
					{
						file << c[l].getCategory() << endl << c[l].getType() << endl << c[l].getBrand() << endl << c[l].getModel() << endl << c[l].getScreenSize() << endl << c[l].getOS() << endl << c[l].getCPU() << endl << c[l].getClockSpeed() << endl << c[l].getColor() << endl << c[l].getResolution() << endl << c[l].getPrice() << endl << c[l].getQuantity() << endl;
					}
				}

				for (int l = 0; l < accessories_Total; l++)
				{
					cout << "l\n\n";
					if (type == 2)
					{
						if (l != found)
						{
							file << a[l].getCategory() << endl << a[l].getType() << endl << a[l].getBrand() << endl << a[l].getModel() << endl << a[l].getConnectType_A() << endl << a[l].getDimension() << endl << a[l].getColor() << endl << a[l].getPrice() << endl << a[l].getQuantity() << endl;
						}
					}
					else
					{
						file << a[l].getCategory() << endl << a[l].getType() << endl << a[l].getBrand() << endl << a[l].getModel() << endl << a[l].getConnectType_A() << endl << a[l].getDimension() << endl << a[l].getColor() << endl << a[l].getPrice() << endl << a[l].getQuantity() << endl;
					}
				}

				for (int l = 0; l < printer_Total; l++)
				{
					if (type == 3)
					{
						if (l != found)
						{
							file << p[l].getCategory() << endl << p[l].getBrand() << endl << p[l].getModel() << endl << p[l].getPrintType() << endl << p[l].getConnectType_P() << endl << p[l].getCompatible() << endl << p[l].getSheetSize() << endl << p[l].getColor() << endl << p[l].getOutputType() << endl << p[l].getPrice() << endl << p[l].getQuantity() << endl;
						}
					}
					else
					{
						file << p[l].getCategory() << endl << p[l].getBrand() << endl << p[l].getModel() << endl << p[l].getPrintType() << endl << p[l].getConnectType_P() << endl << p[l].getCompatible() << endl << p[l].getSheetSize() << endl << p[l].getColor() << endl << p[l].getOutputType() << endl << p[l].getPrice() << endl << p[l].getQuantity() << endl;
					}
				}

				file.close();
				cout << "\n\n  Succesfully Deleted \n";
			}
			else
			{
				cout << "\n\n  Delete Canceled \n";
			}
		}
		cout << "\n  Press Any Key To Go Back...";
		getch();
	}
};


class Menu
{
public:

	static void show()
	{
		cout << "\n       Main Menu    \n";
		cout << "\n  1.View All Products    ";
		cout << "\n  2.Add Details of a Product         ";
		cout << "\n  3.Delete Product Details      ";
		cout << "\n  4.Search For Products/View Selected Product  ";
		cout << "\n  5.Exit                 ";

		cout << "\n\n Select A Function > ";
	}
	static int prompt()
	{
		int option;
		Function f;

		cin >> option;
		system("cls");
		switch (option)
		{
		case 1: f.viewAll(); break;

		case 2: f.addProducts(); break;

		case 3: f.deleteProduct(); break;

		case 4: f.searchProducts(); break;

		case 5: cout << "\n   Have A Nice Day\n\n"; return 0; break;

		default: break;
		}
		return 1;
	}
};


int main()
{
	do
	{
		system("cls");
		Menu::show();
	} while (Menu::prompt() == 1);
}
