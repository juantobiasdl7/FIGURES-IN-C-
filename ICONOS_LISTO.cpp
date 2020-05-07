#include <winbgim.h>
#include<cmath>
#include <iostream> 
using namespace std; 
 struct PASOS
{
      int tipo;
       
       };
       
struct linea
{
       double px1,py1,px2,py2;
       double px,py;
       };

struct circulo
{
       double cx,cy,r1;
       
       };
struct linea2
{
       double px,py;
       };
 struct arco
 {
     double ch,ck,r,B1,B2,ap1,gi1,ag,inca;   
        };

void waitForLeftMouseClick()
{
const int DELAY = 1; 
int A, B;
while (!ismouseclick (WM_LBUTTONDOWN))
{delay(DELAY);}
getmouseclick(WM_LBUTTONDOWN, A, B);
} 


int Fx(int gx)
{
    int x3,x4,x5;
    x3=gx/10;
    x3=x3*10;
    x4=x3+5;
    x5=x3+10;
    
    if(gx>=x3 && gx<x4)
       {
              gx=x3;
              }
              else
              {
                  gx=x5;
                  }
                  return gx;
                  }
                  

int Fy(int gy)
{
    int y3,y4,y5;
    y3=gy/10;
    y3=y3*10;
    y4=y3+5;
    y5=y3+10;
    
    if(gy>=y3 && gy<y4)
       {
              gy=y3;
              }
              else
              {
                  gy=y5;
                  }
                  return gy;
                  }
    
    
int main() 
{
    
linea lin[50];
PASOS pas[50];
circulo cir[50];
arco bir[50];

initwindow(5000,800);
 settextstyle(0,0,2);
 setcolor(14);
 outtextxy(350,5,"PINTA UNA LINEA");
 setcolor(15); 

int px1=0,py1=0,gi,pt,px3,py3,pj,fw=0;//arcs
float xc=0,yc=0, r=0, s=0;                                                              

//VARIABLES JUAN
int x=0,y=0,xS=0,yS=0,i,t,j,w=0,w1=0,w2=0;

     float px,py,x1,x2,y1,y2,y3,x3,rm,A,B,C,h,k,h1,h2,k1,k2,dis,ang,angi,ang1,ang2,m1,m2,app;
	int op,giro,ejex,ejey,pasos,p=0,u=0,v=0;
	long double pi=3.141592653589;
	char l;
float r1=0;


           

//ICONOS
           //LINEA DIAGONAL

 rectangle(50,50,100,100);
 moveto(60,60);
 lineto(90,90);
 
          //DOS RECTANGULOS
 rectangle(50,110,100,160);
             for(gi=55;gi<=70;gi+=5)
{
for(pj=115;pj<=155;pj+=5)
{

             circle(gi,pj,1);  }
}   
 moveto(75,110);
 lineto(75,160);
         //CIRCULO
 rectangle(50,200,100,250);
 moveto(75,275);
 circle(75,225,20);
        //ARCOS
 rectangle(50,350,100,400);
 arc (95,395,90,180,40);
       //SALIR
 rectangle(50,500,100,550);
 arc(75,525,130,50,20);
 line(75,525,75,505);
      //FORZAR
 rectangle(50,600,100,650);
 moveto(75,600);
 lineto(75,650);
 moveto(60,600);
 lineto(60,650);
  moveto(65,600);
 lineto(65,650);
   moveto(50,600);
 lineto(75,650);
    moveto(75,600);
 lineto(50,650);
        //BORRAR
        rectangle(50,700,100,750);
        moveto(67,710);
        lineto(52,720);
        moveto(52,710);
        lineto(67,720);
        
 
       //AREA DE TRABAJO
    rectangle(130,50,1500,750);
// rectangle(800,50,900,100);
// moveto(850,50);
// lineto(850,100); 

// VERIFIAR ICONOS

 I:
            
 waitForLeftMouseClick();
 px=mousex( );
 py=mousey( ); 
 
setcolor(15);
 if ( px>= 50 && px<= 75 &&  py>= 600 && py<= 650) goto FORZAR;
  if ( px>= 75 && px<= 100 &&  py>= 600 && py<= 650) goto I;
  if ( px>= 50 && px<= 100 &&  py>= 50 && py<= 100)  {p=p+1; pas[p].tipo=1; goto LINEA;}
  if ( px>= 50 && px<= 100 &&  py>= 200 && py<= 250){ p=p+1; pas[p].tipo=2; goto CIRCULO;}
  if (px>=50 && px<=100 && py>=500 &&py<=550)goto CERRAR;
  if(px>=50&&px<=100&&py>=700&&py<=750)goto BORRAR;
  if(px>=50&&px<=100&&py>=350&&py<=400){p=p+1; pas[p].tipo=3;goto ARCOS;}
  if(px>=50&&px<=75&&py>=110&&py<=160) goto PUNTOS;
   if(px>=75&&px<=100&&py>=110&&py<=160)goto NEGRO;
  
 goto I;
 //LINEAS___________________________________________________________________________________________

 LINEA:
while(1)
{
 waitForLeftMouseClick();
 px=mousex( );
 py=mousey( );


waitForLeftMouseClick();
 px1=mousex( );
 py1=mousey( );

if ( px>= 130 && px<= 1500 &&  py>= 50 && py<= 750 && px1>= 130 && px1<= 1500 &&  py1>= 50 && py1<= 750)
{
     
line(px,py,px1,py1); 
u=u+1;
lin[u].px1=px;
lin[u].py1=py;
lin[u].px2=px1;
lin[u].py2=py1;   
}
break;
}
goto I;

//CIRCULOS__________________________________________________________________________________________________________
CIRCULO:

while(1)
{

 waitForLeftMouseClick();
 px=mousex( );
 py=mousey( );

 

waitForLeftMouseClick();
 px1=mousex( );
 py1=mousey( );

 

    //radio

xc = (px1-px);  
xc = xc*xc;

yc = (py1-py);  
yc = yc*yc;

r=sqrt((xc+yc));

circle(px,py,r);
v=v+1;
cir[v].cx=px;
cir[v].cy=py;
cir[v].r1=r;
break;
}
goto I;
//PINTA LOS PUNTOS______________________________________________________________________________________________________
PUNTOS:
       fw=1;
       while(1)
       {
for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}        
break;
}            
goto I;
//_______________________________________________________________________________________________________________________

//BORRA LOS PUNTOS_______________________________________________________________________________________________________
NEGRO:
       fw=2;
      while(1)
      {
 setcolor(0);
            for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}         
break;
}           
goto I;

//________________________________________________________________________________________________________________________
//ARCOS________________________________________________________________________________________________________________________
ARCOS:

while(1)
{
        
       
       
	Posicion:
	system("cls");
    waitForLeftMouseClick();
	cout<<endl<<"Movimiento en arco"<<endl<<endl<<"Introduzca posicion inicial x,y"<<endl;
	x1=mousex();

	y1=mousey();

	 waitForLeftMouseClick();
	cout<<endl<<"Introduzca  posicion final x,y"<<endl;
	x2=mousex();
	
	y2=mousey();


	 
	 
	rm=(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))/2;
	if(rm==0)
	{
		cout<<"No hay distancia entre los puntos"<<endl<<"Imposible trazar arco"<<endl;
		system("pause");
		goto Posicion;
	}
	Radio:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<endl<<"Introduzca radio de giro"<<endl<<"Radio minimo = "<<rm<<endl;
	cin>>r;
	if(r<rm)
	{
		cout<<endl<<"Radio invalido"<<endl;
		system("pause");
		goto Radio;
	}
	Centros:
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl;
	y3=y2-y1;
	x3=x2-x1;
	if(x3==0&&y3!=0)
	{
		A=((x3*x3)/(y3*y3))+1;
		B=(-1)*(x3+((x3*x3*x3)/(y3*y3)));
		C=((x3*x3*x3*x3)/(4*y3*y3))+((y3*y3)/(4))+((x3*x3)/2)-(r*r);
		dis=(B*B)-4*A*C;
		dis=sqrt(dis);
		h1=((-1*B)+dis)/(2*A);
		h2=((-1*B)-dis)/(2*A);
		k1=(y3/2)+y1;
		k2=(y3/2)+y1;
		h1=h1+x1;
		h2=h2+x1;
	}
	else
	{
		A=((y3*y3)/(x3*x3))+1;
		B=(-1)*(y3+((y3*y3*y3)/(x3*x3)));
		C=((y3*y3*y3*y3)/(4*x3*x3))+((x3*x3)/(4))+((y3*y3)/2)-(r*r);
		dis=(B*B)-4*A*C;
		dis=sqrt(dis);
		k1=((-1*B)+dis)/(2*A);
		k2=((-1*B)-dis)/(2*A);
		h1=((y3*y3)/(2*x3))+(x3/2)-(k1*y3/x3)+x1;
		h2=((y3*y3)/(2*x3))+(x3/2)-(k2*y3/x3)+x1;
		k1=k1+y1;
		k2=k2+y1;
	}
	Escoger:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<endl;	
	if(h1==h2&&k1==k2)
	{
		cout<<"Centro unico en = ("<<h1<<","<<k1<<")"<<endl;
		h=h1;
		k=k1;
		system("pause");
	}
	else
	{
		cout<<"Escoger centro:"<<endl<<"1. Centro 1 = ("<<h1<<","<<k1<<")"<<endl<<"2. Centro 2 = ("<<h2<<","<<k2<<")"<<endl; 
		cin>>op;
		switch(op)
		{
			case 1:
				h=h1;
				k=k1;
				break;
			case 2:
				h=h2;
				k=k2;
				break;
			default:
				goto Escoger;
		}
	}
	Giro:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<"Centro en ("<<h<<","<<k<<")"<<endl;
	cout<<endl<<"Escoger sentido del giro:"<<endl<<"1. Horario"<<endl<<"2. Antihorario"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			giro=-1;
			break;
		case 2:
			giro=1;
			break;
		default:
			goto Giro;
	}
	Datos:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<"Centro en ("<<h<<","<<k<<")"<<endl;
	if(giro==1)
	{
		cout<<"Sentido antihorario"<<endl<<endl;
	}
	else if(giro==-1)
	{
		cout<<"Sentido horario"<<endl<<endl;
	}
	cout<<endl<<"1. Confirmar datos"<<endl<<"2. Introducir nuevos datos"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			break;
		case 2:
			goto Posicion;
			break;
		default:
			goto Datos;
			break;
	}
	Angulo:
	if(r==rm)//180 grados
	{
		ang=180;
		if(k-y1==0||h-x1==0&&k-y2==0||h-x2==0)
		{
			if(x2>x1)
			{
				angi=180;
			}
			else if(x1>x2)
			{
				angi=0;
			}
			else if(x2==x1)
			{
				if(y2>y1)
				{
					angi=270;
				}
				else if(y1>y2)
				{
					angi=90;
				}
			}
		}
		else 
		{
			x3=x1-h;
			y3=y1-k;
			angi=(atan((y3)/(x3)))*(180/pi);
			if(x3<0&&y3>0||x3<0&&y3<0)
			{
				angi=180+angi;
			}
			else
			{
				angi=360+angi;
			}
		}
	}
	else if (k-y1==0||h-x1==0&&k-y2==0||h-x2==0) //90 grados
	{	
		if(h==x2&&k==y1)
		{
			if(h>x1)
			{
				angi=180;
				if(k<y2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
				else if(k>y2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
			}
			else if(h<x1)
			{
				angi=0;
				if(k<y2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
				else if(k>y2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}	
			}
		}
		else if(h==x1&&k==y2)
		{
			if(k>y1)
			{
				angi=270;
				if(h<x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
				else if(h>x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
			}
			else if(k<y1)
			{
				angi=90;
				if(h>x2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
				else if(h<x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}	
			}
		}
	}
	else //x grados
	{
		x3=x2-h;
		y3=y2-k;
		ang2=atan(y3/x3)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			ang2=180+ang2;
		}
		else if(x3>0&&y3<0)
		{
			ang2=360+ang2;
		}
		x3=x1-h;
		y3=y1-k;
		ang1=atan(y3/x3)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			ang1=180+ang1;
		}
		else if(x3>0&&y3<0)
		{
			ang1=360+ang1;
		}
		m1=(y1-k)/(x1-h);
		m2=(y2-k)/(x2-h);
		ang=ang2-ang1;
		cout<<"ang ="<<ang<<endl;
		if(ang>0)
		{
			ang2=ang;
			ang1=360-ang;
		}
		else if(ang<0)
		{
			ang1=ang*-1;
			ang=sqrt(ang*ang);
			ang2=360-ang;
		}
		if(giro==1)
		{
			ang=ang2;
		}
		else if(giro==-1)
		{
			ang=ang1;
		}
		angi=atan(m1)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			angi=angi+180;
		}
		else if(x3>0&&y3<0)
		{
			angi=angi+360;
		}
	}
	pasos=ang;
	app=ang/pasos;
	px=x1;
	py=y1;
	
         
	for(int i=0;i<=pasos;i++)
	{
          
        moveto(px,py);
		px=r*(cos((i*app*giro+angi)*(pi/180)))+h;
		py=r*(sin((i*app*giro+angi)*(pi/180)))+k;
	    lineto(px,py);
		
	}   
	w=w+1;
bir[w].ch=h;
bir[w].ck=k;
bir[w].r=r;
bir[w].B1=px;
bir[w].B2=py;
bir[w].ap1=app;
bir[w].gi1=giro;
bir[w].ag=angi;
bir[w].inca=i;
break;  
system("cls");    



            
                       
                   break; 
}
goto I;
//________________________________________________________________________________________________________________________

CERRAR:
closegraph();   
//__________________________________________________________________________________________________________________

BORRAR:

 while(1){
          
                p=p;
                if(pas[p].tipo==1){
                                   u=u;
                                   setcolor(0);
                                   line(lin[u].px1,lin[u].py1,lin[u].px2,lin[u].py2);
                                   u=u-1;                
                                   }
                else if(pas[p].tipo==2){
                                         v=v;
                                         setcolor(0);
                                         circle(cir[v].cx,cir[v].cy,cir[v].r1);
                                         v=v-1;                
                                        }
                else if(pas[p].tipo==3){
                                         w=w;
                                         setcolor(0);
                                        	pasos=ang;
	app=ang/pasos;
	bir[w].B1=x1;
	bir[w].B2=y1;
	
         
	for(int i=0;i<=pasos;i++)
	{
          setlinestyle(SOLID_LINE,0,5);
        moveto(bir[w].B1,bir[w].B2);
		bir[w].B1=bir[w].r*(cos((i*bir[w].ap1*bir[w].gi1+bir[w].ag)*(pi/180)))+bir[w].ch;
		bir[w].B2=bir[w].r*(sin((i*bir[w].ap1*bir[w].gi1+bir[w].ag)*(pi/180)))+bir[w].ck;
	    lineto(bir[w].B1,bir[w].B2);
	    circle(bir[w].ch,bir[w].ck,bir[w].r);
		setlinestyle(SOLID_LINE,0,1);  
	}   
                                                    
                        w=w-1;                
                           system("cls");             
                                                      
                                        }
    setcolor(15);
       if(fw==1)
                                           {
       while(1)
       {
for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}        
break;
}   
} 
                p=p-1;
                
                break;
                }
                setcolor(15);
goto I; 

//FORZAR_______________________________________________FORZAR________________________________________________________FORZAR
//FORZAR_______________________________________________FORZAR________________________________________________________FORZAR
//FORZAR_______________________________________________FORZAR________________________________________________________FORZAR
 FORZAR:
            
 waitForLeftMouseClick();
 px=mousex( );
 py=mousey( ); 
 
setcolor(15);
 
  if ( px>= 75 && px<= 100 &&  py>= 600 && py<= 650) goto I;
  if ( px>= 50 && px<= 100 &&  py>= 50 && py<= 100)  {p=p+1; pas[p].tipo=1; goto LINEA1;}
  if ( px>= 50 && px<= 100 &&  py>= 200 && py<= 250){ p=p+1; pas[p].tipo=2; goto CIRCULO1;}
  if (px>=50 && px<=100 && py>=500 &&py<=550)goto CERRAR;
  if(px>=50&&px<=100&&py>=700&&py<=750)goto BORRAR1;
  if(px>=50&&px<=100&&py>=350&&py<=400){p=p+1; pas[p].tipo=3;goto ARCOS1;}
  if(px>=50&&px<=75&&py>=110&&py<=160) goto PUNTOS1;
   if(px>=75&&px<=100&&py>=110&&py<=160)goto NEGRO1;
   //LINEA1__________________________________________FORZAR______________________________________________________________________
 LINEA1:
while(1)
{
 waitForLeftMouseClick();
 px=mousex( );
 px=Fx(px);
 py=mousey( );
 py=Fy(py);

waitForLeftMouseClick();
 px1=mousex( );
 px1=Fx(px1);
 py1=mousey( );
 py1=Fy(py1);

if ( px>= 130 && px<= 1500 &&  py>= 50 && py<= 750 && px1>= 130 && px1<= 1500 &&  py1>= 50 && py1<= 750)
{
     
line(px,py,px1,py1); 
u=u+1;
lin[u].px1=px;
lin[u].py1=py;
lin[u].px2=px1;
lin[u].py2=py1;   
}
break;
}
goto FORZAR;
//CIRCULOS1__________________________________________________________________________________________________________
CIRCULO1:

while(1)
{

 waitForLeftMouseClick();
 px=mousex( );
 px=Fx(px);
 py=mousey( );
py=Fy(py);
 

waitForLeftMouseClick();
 px1=mousex( );
 px1=Fx(px1);
 py1=mousey( );
 py1=Fy(py1);

 

    //radio

xc = (px1-px);  
xc = xc*xc;

yc = (py1-py);  
yc = yc*yc;

r=sqrt((xc+yc));

circle(px,py,r);
v=v+1;
cir[v].cx=px;
cir[v].cy=py;
cir[v].r1=r;
break;
}
goto FORZAR;
//PINTA LOS PUNTOS__________________________________________NOFORZAR____________________________________________________________
PUNTOS1:
        fw=1;
       while(1)
       {
for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}        
break;
}            
goto FORZAR;
//_______________________________________________________________________________________________________________________
//BORRA LOS PUNTOS__________________________________________NOFORZAR_____________________________________________________________
NEGRO1:
       fw=2;
      while(1)
      {
 setcolor(0);
            for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}         
break;
}           
goto FORZAR;
//ARCOS1________________________________________________________________________________________________________________________
ARCOS1:
while(1)
{
        
       
       
	Posicion2:
	system("cls");
	cout<<endl<<"Movimiento en arco"<<endl<<endl<<"Introduzca posicion inicial x,y"<<endl;
	 waitForLeftMouseClick();
    x1=mousex();
	x1=Fx(x1);
	y1=mousey();
	y1=Fy(y1);
	 waitForLeftMouseClick();
	cout<<endl<<"Introduzca  posicion final x,y"<<endl;
	x2=mousex();
	x2=Fx(x2);
	y2=mousey();
	y2=Fy(y2);

	 
	 
	rm=(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))/2;
	if(rm==0)
	{
		cout<<"No hay distancia entre los puntos"<<endl<<"Imposible trazar arco"<<endl;
		system("pause");
		goto Posicion2;
	}
	Radio2:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<endl<<"Introduzca radio de giro"<<endl<<"Radio minimo = "<<rm<<endl;
	cin>>r;
	if(r<rm)
	{
		cout<<endl<<"Radio invalido"<<endl;
		system("pause");
		goto Radio2;
	}
	Centros2:
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl;
	y3=y2-y1;
	x3=x2-x1;
	if(x3==0&&y3!=0)
	{
		A=((x3*x3)/(y3*y3))+1;
		B=(-1)*(x3+((x3*x3*x3)/(y3*y3)));
		C=((x3*x3*x3*x3)/(4*y3*y3))+((y3*y3)/(4))+((x3*x3)/2)-(r*r);
		dis=(B*B)-4*A*C;
		dis=sqrt(dis);
		h1=((-1*B)+dis)/(2*A);
		h2=((-1*B)-dis)/(2*A);
		k1=(y3/2)+y1;
		k2=(y3/2)+y1;
		h1=h1+x1;
		h2=h2+x1;
	}
	else
	{
		A=((y3*y3)/(x3*x3))+1;
		B=(-1)*(y3+((y3*y3*y3)/(x3*x3)));
		C=((y3*y3*y3*y3)/(4*x3*x3))+((x3*x3)/(4))+((y3*y3)/2)-(r*r);
		dis=(B*B)-4*A*C;
		dis=sqrt(dis);
		k1=((-1*B)+dis)/(2*A);
		k2=((-1*B)-dis)/(2*A);
		h1=((y3*y3)/(2*x3))+(x3/2)-(k1*y3/x3)+x1;
		h2=((y3*y3)/(2*x3))+(x3/2)-(k2*y3/x3)+x1;
		k1=k1+y1;
		k2=k2+y1;
	}
	Escoger2:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<endl;	
	if(h1==h2&&k1==k2)
	{
		cout<<"Centro unico en = ("<<h1<<","<<k1<<")"<<endl;
		h=h1;
		k=k1;
		system("pause");
	}
	else
	{
		cout<<"Escoger centro:"<<endl<<"1. Centro 1 = ("<<h1<<","<<k1<<")"<<endl<<"2. Centro 2 = ("<<h2<<","<<k2<<")"<<endl; 
		cin>>op;
		switch(op)
		{
			case 1:
				h=h1;
				k=k1;
				break;
			case 2:
				h=h2;
				k=k2;
				break;
			default:
				goto Escoger2;
		}
	}
	Giro2:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<"Centro en ("<<h<<","<<k<<")"<<endl;
	cout<<endl<<"Escoger sentido del giro:"<<endl<<"1. Horario"<<endl<<"2. Antihorario"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			giro=-1;
			break;
		case 2:
			giro=1;
			break;
		default:
			goto Giro2;
	}
	Datos2:
	system("cls");
	cout<<"Datos= "<<endl<<"Posicion incial en ("<<x1<<","<<y1<<")"<<endl<<"Posicion final en ("<<x2<<","<<y2<<")"<<endl<<"Radio de "<<r<<endl<<"Centro en ("<<h<<","<<k<<")"<<endl;
	if(giro==1)
	{
		cout<<"Sentido antihorario"<<endl<<endl;
	}
	else if(giro==-1)
	{
		cout<<"Sentido horario"<<endl<<endl;
	}
	cout<<endl<<"1. Confirmar datos"<<endl<<"2. Introducir nuevos datos"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			break;
		case 2:
			goto Posicion2;
			break;
		default:
			goto Datos2;
			break;
	}
	Angulo2:
	if(r==rm)//180 grados
	{
		ang=180;
		if(k-y1==0||h-x1==0&&k-y2==0||h-x2==0)
		{
			if(x2>x1)
			{
				angi=180;
			}
			else if(x1>x2)
			{
				angi=0;
			}
			else if(x2==x1)
			{
				if(y2>y1)
				{
					angi=270;
				}
				else if(y1>y2)
				{
					angi=90;
				}
			}
		}
		else 
		{
			x3=x1-h;
			y3=y1-k;
			angi=(atan((y3)/(x3)))*(180/pi);
			if(x3<0&&y3>0||x3<0&&y3<0)
			{
				angi=180+angi;
			}
			else
			{
				angi=360+angi;
			}
		}
	}
	else if (k-y1==0||h-x1==0&&k-y2==0||h-x2==0) //90 grados
	{	
		if(h==x2&&k==y1)
		{
			if(h>x1)
			{
				angi=180;
				if(k<y2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
				else if(k>y2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
			}
			else if(h<x1)
			{
				angi=0;
				if(k<y2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
				else if(k>y2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}	
			}
		}
		else if(h==x1&&k==y2)
		{
			if(k>y1)
			{
				angi=270;
				if(h<x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
				else if(h>x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}
			}
			else if(k<y1)
			{
				angi=90;
				if(h>x2)
				{
					if(giro==1)
					{
						ang=90;
					}
					else if(giro==-1)
					{
						ang=270;
					}
				}
				else if(h<x2)
				{
					if(giro==1)
					{
						ang=270;
					}
					else if(giro==-1)
					{
						ang=90;
					}
				}	
			}
		}
	}
	else //x grados
	{
		x3=x2-h;
		y3=y2-k;
		ang2=atan(y3/x3)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			ang2=180+ang2;
		}
		else if(x3>0&&y3<0)
		{
			ang2=360+ang2;
		}
		x3=x1-h;
		y3=y1-k;
		ang1=atan(y3/x3)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			ang1=180+ang1;
		}
		else if(x3>0&&y3<0)
		{
			ang1=360+ang1;
		}
		m1=(y1-k)/(x1-h);
		m2=(y2-k)/(x2-h);
		ang=ang2-ang1;
		cout<<"ang ="<<ang<<endl;
		if(ang>0)
		{
			ang2=ang;
			ang1=360-ang;
		}
		else if(ang<0)
		{
			ang1=ang*-1;
			ang=sqrt(ang*ang);
			ang2=360-ang;
		}
		if(giro==1)
		{
			ang=ang2;
		}
		else if(giro==-1)
		{
			ang=ang1;
		}
		angi=atan(m1)*(180/pi);
		if(x3<0&&y3>0||x3<0&&y3<0)
		{
			angi=angi+180;
		}
		else if(x3>0&&y3<0)
		{
			angi=angi+360;
		}
	}
	pasos=ang;
	app=ang/pasos;
	px=x1;
	py=y1;
	
         
	for(int i=0;i<=pasos;i++)
	{
          
        moveto(px,py);
		px=r*(cos((i*app*giro+angi)*(pi/180)))+h;
		py=r*(sin((i*app*giro+angi)*(pi/180)))+k;
	    lineto(px,py);
		
	}
	

	w=w+1;
bir[w].ch=h;
bir[w].ck=k;
bir[w].r=r;
bir[w].B1=px;
bir[w].B2=py;
bir[w].ap1=app;
bir[w].gi1=giro;
bir[w].ag=angi;
bir[w].inca=i;
  break;
system("cls");    
break;   }
goto FORZAR;
//__________________________________________________________________________________________________________________

BORRAR1:

 while(1){
          
                p=p;
                if(pas[p].tipo==1){
                                   u=u;
                                   setcolor(0);
                                   line(lin[u].px1,lin[u].py1,lin[u].px2,lin[u].py2);
                                   u=u-1;                
                                   }     
                else if(pas[p].tipo==2){
                                         v=v;
                                         setcolor(0);
                                         circle(cir[v].cx,cir[v].cy,cir[v].r1);
                                         v=v-1;                
                                        }
                else if(pas[p].tipo==3){
                                         w=w;
                                         setcolor(0);
                                        	pasos=ang;
	app=ang/pasos;
	bir[w].B1=x1;
	bir[w].B2=y1;
	
         
	for(int i=0;i<=pasos;i++)
	{
 setlinestyle(SOLID_LINE,0,5);
        moveto(bir[w].B1,bir[w].B2);
		bir[w].B1=bir[w].r*(cos((i*bir[w].ap1*bir[w].gi1+bir[w].ag)*(pi/180)))+bir[w].ch;
		bir[w].B2=bir[w].r*(sin((i*bir[w].ap1*bir[w].gi1+bir[w].ag)*(pi/180)))+bir[w].ck;
	    lineto(bir[w].B1,bir[w].B2);
	    circle(bir[w].ch,bir[w].ck,bir[w].r);
	    setlinestyle(SOLID_LINE,0,1);
	    
		
	}                 
                         // setlinestyle(SOLID_LINE,0,1);               
                        w=w-1;                
                           system("cls");             
                                                      
                                        }
                                        setcolor(15);
       if(fw==1)
                                           {
       while(1)
       {
for(gi=140;gi<=1490;gi+=10)
{
for(pj=60;pj<=740;pj+=10)
{

             circle(gi,pj,1);  }
}        
break;
}   
} 
                p=p-1;
                
                break;
                }
                setcolor(15);
                goto FORZAR;
}
