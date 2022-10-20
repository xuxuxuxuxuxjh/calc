#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("计算器");

    QFont f("仿宋",14);
    ui->mainLineEdit->setFont(f);

    QIcon con("C:\\Users\\xuxuxuxuxu\\Desktop\\del.png");
    ui->ButtonDel->setIcon(con);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button1_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button2_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button3_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button4_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button5_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button6_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button7_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button8_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button9_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonClear_clicked()
{
    expression ="";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonAdd_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonSub_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonMul_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonDiv_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button0_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonL_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonR_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonDel_clicked()
{
    int len=expression.size();
    QString A;
    for(int i=1;i<len;i++)A+=expression[i-1];
    expression=A;
    ui->mainLineEdit->setText(expression);
}

int change(QChar c)
{
    if(c=='0')return 0;
    if(c=='1')return 1;
    if(c=='2')return 2;
    if(c=='3')return 3;
    if(c=='4')return 4;
    if(c=='5')return 5;
    if(c=='6')return 6;
    if(c=='7')return 7;
    if(c=='8')return 8;
    if(c=='9')return 9;
    return 0;
}

#define int long long

QChar change2(int c)
{
    if(c==0)return '0';
    if(c==1)return '1';
    if(c==2)return '2';
    if(c==3)return '3';
    if(c==4)return '4';
    if(c==5)return '5';
    if(c==6)return '6';
    if(c==7)return '7';
    if(c==8)return '8';
    if(c==9)return '9';
    return '0';
}
int Val(QString s)
{
    int n=s.size();
    int res=0;
    for(int i=0;i<n;i++)
        res=res*10+change(s[i]);
    return res;
}

void Widget::on_ButtonEquel_clicked()
{
    QChar zhan[105];
    int len=expression.size();
    int tot=0,n=0;
    QString xu;
    QString a[105];
    for(int i=1;i<=len;i++)
    {
        QChar c=expression[i-1];
        if(c>='0'&&c<='9')xu+=c;
        else{
            if(xu!="")a[++n]=xu;
            xu="";
        }
        if(c=='(')zhan[++tot]=c;
        if(c=='+'||c=='-')
        {
            while(tot>0&&zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c=='*'||c=='/')
        {
            while(tot>0&&(zhan[tot]=='*'||zhan[tot]=='/'))
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c==')')
        {
            while(zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            tot--;
        }
    }
    if(xu!="")a[++n]=xu;
    while(tot>0)
    {
        a[++n]=zhan[tot];
        tot--;
    }
    tot=0;
    int Ans[105];
    for(int i=1;i<=n;i++)
    {
        if(a[i]=="+")
        {
            Ans[tot-1]+=Ans[tot];
            tot--;
        }
        else if(a[i]=="-")
        {
            Ans[tot-1]-=Ans[tot];
            tot--;
        }
        else if(a[i]=="*")
        {
            Ans[tot-1]*=Ans[tot];
            tot--;
        }
        else if(a[i]=="/")
        {
            Ans[tot-1]/=Ans[tot];
            tot--;
        }
        else{
            Ans[++tot]=Val(a[i]);
        }
    }
    expression="";
    n=0;
    QChar xjh[105];
    while(Ans[1]>0)
    {
        xjh[++n]=change2(Ans[1]%10);
        Ans[1]/=10;
    }
    for(int i=n;i;i--)expression+=xjh[i];
    ui->mainLineEdit->setText(expression);
}

