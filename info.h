#include <string>
#include <iostream>
#include <fstream>



using namespace std;
ref class Write { //1
    public:
        static void AddTextToListBox(System::Windows::Forms::ListBox^ listBox1, System::String^ text)
        {
            listBox1->Items->Add(text);
        }
};


ref class Info //2
{
    public:
    

    static void AddTextBoxTextToListBox(System::Windows::Forms::ListBox^ listBox, System::Windows::Forms::TextBox^ textBox1, System::Windows::Forms::TextBox^ textBox2, System::Windows::Forms::TextBox^ textBox3, System::Windows::Forms::TextBox^ textBox4)
{
        System::String^ text = textBox1->Text + "/" + textBox2->Text + "/" + textBox3->Text + "/" + textBox4->Text;
        Write::AddTextToListBox(listBox, text);
}

    
};

ref class File { //3
public:
    static void WriteToFile(System::String^ filename, System::Windows::Forms::ListBox^ listBox)
    {
        std::ofstream file(ConvertToStdString(filename));

        if (file.is_open())
        {
            for (int i = 0; i < listBox->Items->Count; i++)
            {
                System::String^ item = listBox->Items[i]->ToString();
                std::string line = ConvertToStdString(item) + "\n";
                file.write(line.c_str(), line.size());
            }

            file.close();
            System::Windows::Forms::MessageBox::Show("Veriler dosyaya yazýldý.");
        }
        else
        {
            System::Windows::Forms::MessageBox::Show("Dosya oluþturulamadý.");
        }
    }

    static std::string ConvertToStdString(System::String^ str)
    {
        std::string result;
        for (int i = 0; i < str->Length; i++)
        {
            result += static_cast<char>(str[i]);
        }
        return result;
    }

    static double CalculateAverage(System::Windows::Forms::TextBox^ textBox)
    {
        if (!System::String::IsNullOrEmpty(textBox->Text))
        {
            double grade = System::Convert::ToDouble(textBox->Text);
            return grade;
        }
        return 0;
    }
};
ref class Student //4
{
public:
    static void CalculateAndSaveAverage(System::String^ filename, System::Windows::Forms::ListBox^ listBox,
        System::Windows::Forms::TextBox^ textBox1, System::Windows::Forms::TextBox^ textBox2,
        System::Windows::Forms::TextBox^ textBox3, System::Windows::Forms::TextBox^ textBox4,
        System::Windows::Forms::TextBox^ textBox5, System::Windows::Forms::TextBox^ textBox6,
        System::Windows::Forms::TextBox^ textBox7, System::Windows::Forms::TextBox^ textBox8,
        System::Windows::Forms::TextBox^ textBox9, System::Windows::Forms::TextBox^ textBox10,
        System::Windows::Forms::TextBox^ textBox11, System::Windows::Forms::TextBox^ textBox12)
    {
        double average = CalculateAverage(textBox5, textBox6, textBox7, textBox8, textBox9, textBox10, textBox11, textBox12);

        System::String^ text = "Average Grade = " + average.ToString();
        Write::AddTextToListBox(listBox, text);

        File::WriteToFile(filename, listBox);
    }

private:
    static double CalculateAverage(System::Windows::Forms::TextBox^ textBox5, System::Windows::Forms::TextBox^ textBox6,
        System::Windows::Forms::TextBox^ textBox7, System::Windows::Forms::TextBox^ textBox8,
        System::Windows::Forms::TextBox^ textBox9, System::Windows::Forms::TextBox^ textBox10,
        System::Windows::Forms::TextBox^ textBox11, System::Windows::Forms::TextBox^ textBox12)
    {
        double total = 0;
        int count = 0;

        total += File::CalculateAverage(textBox5);
        total += File::CalculateAverage(textBox6);
        total += File::CalculateAverage(textBox7);
        total += File::CalculateAverage(textBox8);
        total += File::CalculateAverage(textBox9);
        total += File::CalculateAverage(textBox10);
        total += File::CalculateAverage(textBox11);
        total += File::CalculateAverage(textBox12);

        count += !System::String::IsNullOrEmpty(textBox5->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox6->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox7->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox8->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox9->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox10->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox11->Text) ? 1 : 0;
        count += !System::String::IsNullOrEmpty(textBox12->Text) ? 1 : 0;

        if (count > 0)
            return total / count;

        return 0;
    }
};
ref class Reset //5
{
public:
    static void ResetTextBoxes(System::Windows::Forms::TextBox^ textBox1, System::Windows::Forms::TextBox^ textBox2,
        System::Windows::Forms::TextBox^ textBox3, System::Windows::Forms::TextBox^ textBox4,
        System::Windows::Forms::TextBox^ textBox5, System::Windows::Forms::TextBox^ textBox6,
        System::Windows::Forms::TextBox^ textBox7, System::Windows::Forms::TextBox^ textBox8,
        System::Windows::Forms::TextBox^ textBox9, System::Windows::Forms::TextBox^ textBox10,
        System::Windows::Forms::TextBox^ textBox11, System::Windows::Forms::TextBox^ textBox12)
    {
        textBox1->Text = "";
        textBox2->Text = "";
        textBox3->Text = "";
        textBox4->Text = "";
        textBox5->Text = "";
        textBox6->Text = "";
        textBox7->Text = "";
        textBox8->Text = "";
        textBox9->Text = "";
        textBox10->Text = "";
        textBox11->Text = "";
        textBox12->Text = "";
    }
};

