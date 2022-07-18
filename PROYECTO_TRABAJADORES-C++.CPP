 //INTEGRANTES:*****EQUIPO 8*******
 /*DISEÑAR UN PROGRAMA QUE A TRAVES DE UN MENU DE OPCIONES REALICE LO SIGUENTE:
 INSERTAR DATOS, REPORTES (EN GENERAL, POR CATEGORIA), ELIMINAR DATO, MODIFICAR
 DATO, CONSULTAR DATOS, ORDENAR DATOS Y SALIR. EL PROGRAMA TRATARA DEL INGRESO DE LOS
 TRABAJADORES DE UNA EMPRESA CON LOS SIGUIENTES DATOS: CODIGO DEL TRABAJADOR,
 APELLIDOS Y NOMBRES, CATEGORIA (AUXILIAR, TECNICO O PROFESIONAL), SEXO, ESTADO
 CIVIL (SOLTERO O CASADO), PROFESION U OCUPACION, CARGO (OBRERO,ADMINISTRATIVO
 ,JEFE O DIRECTOR), SUELDO BASICO, BONIFICACION, DESCUENTO, BONIFICACION POR
 RIESGO DE VIDA(SOLO PARA OBREROS), BONIFICACION POR CAPACITACION (SOLO PARA
 TECNICOS), RETENCION DE IMPUESTOS (SOLO PARA PROFESINALES). APLICAR
 FUNCIONES CON PASO DE PARAMETROS.*/
 #include <iostream.h>
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>
 #include <string.h>
 void MENU (int opc);
 void insertar(char cat[],int E);
 void Menu_Mostrar();
 void Mostrar_Cat();
 void Mostrar_Aux(char cat[15]);
 void Mostrar();
 void Modificar(char cat[], int E);
 void modificar_menu(int E);
 void escribirdin(char cat[15]);
 void llenarlista(char cat[15]);
 bool confirmar(char cat[]);
 int cantidad(char cat[]);
 void eliminar_menu(int E);
 void BusPro(char cat[], char pro[],bool *band);
 void BusCar(char cat[], char car[],bool *band);
 void BusNom(char cat[], char nom[],bool *band);
 void BusCod(char cat[], char cod[],bool *band);
 void Ordenamiento_Eleccion(char cat[],int E);
 void ordenar_menu(int E);
 void eleccion(char cat[]);
 void datos();
 void Busqueda();
 void Eliminar(char cat[], int E);
 struct Trabajador
 {
   char cod[15];
   char nom[30];
   char cat[15];
   char sex[3];
   char esci[15];
   char pro[15];
   char car[15];
   float sb;
   float BonT;
   float DescT;
   float Nt;
 }x;
 typedef struct Nodo{
     struct Trabajador li;
     struct Nodo *sig;
 }listar;;
 listar *comienzo;
 #define tam sizeof(listar)
 FILE *p;
 int c=2;
 bool confirmar(char cat[])
 {
	bool b=true;
	p=fopen(cat,"rb");
   if(p==NULL){
   	fclose(p);
      b=false;
   }
   fclose(p);
   return b;
 }
 int cantidad(char cat[]){
	p=fopen(cat,"rb");
   int a=0;
   fseek(p,0,SEEK_SET);
	while(fread(&x,sizeof(x),1,p)>0)
   {
		a++;
   }
   fclose(p);
   return a;
 }
 void main(){

 	int opc;
   do
 	{
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t            VENTANA        "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t----------------------------"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t1.- Gestion de Datos Estatico"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t2.- Gestion de Datos Dinamico"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Salir                   "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t----------------------------"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\tIngrese su opcion==>";
		cin>>opc;
      while(c>=2 && opc==1)
      {
        cout<<"\n";
        cout<<" \t\t\t\t\t\t\t\t\tLA CAPACIDAD MAXIMA DE FORMA ESTATICA ESTA SUPERA."<<endl;
        cout<<" \t\t\t\t\t\t\t\t\t          VUELVA A ELEGIR LA OPCION"<<endl;
        cout<<" \n\t\t\t\t\t\t\t\t\tIngrese su opcion==>";
        cin>>opc;
        clrscr();
      }
   	switch (opc)
   	{
       case 1:
              {
                 MENU(opc);
              }
       case 2:
              {
                 MENU(opc);
              }
      }
   }while(opc<3);
 }
 void MENU (int opc){

 	int opc2;
 	do
 	{
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t            MENU"        <<endl;
		cout<<" \t\t\t\t\t\t\t\t\t----------------------------"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t1.- Insertar  Datos         "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t2.- Mostrar   Datos         "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t3.- Eliminar   Datos         "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t4.- Modificar Datos         "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t5.- Consultar Datos         "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t6.- Ordenar  Datos         "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t7.- Salir                   "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t----------------------------"<<endl;
		cout<<" \t\t\t\t\t\t\t\t\tIngrese su opcion==>";
		cin>>opc2;
   	switch (opc2)
   	{
       case 1:
              {
       				char cat[15];
                  do
                  {
      					cout<<"Que categoria quisiera Ingresar(Auxiliar,Tecnico,Profesional): ";
      	      		cin>>cat;
               	}
                  while(strcmp(cat,"Auxiliar")!=0 && strcmp(cat,"Tecnico")!=0 && strcmp(cat,"Profesional")!=0);
                 	insertar(cat,opc);
                  break;
              }
   	 case 2: {
			      	Menu_Mostrar();break;
               }
       case 3: {
                 	eliminar_menu(opc);
                  break;
       			}
		 case 4: {
                 	modificar_menu(opc);
                  break;
       			}
       case 5: {
                 	Busqueda();
                  break;
       			}
		 case 6: {
                 	ordenar_menu(opc);
                  break;
       			}
      }
   }while(opc2<7);
}
void insertar(char cat[],int E)
{
  clrscr();
  int opc;
  if(E==1){
  	  while(1){
      	eleccion(cat);
         c++;
     		if(c==2){
      		cout<<"Ya se alcanzo el tope maximo para  la forma estatica.\nPase a la forma Dinamica";
            getch();
            break;
	      }
     }
  }else{
	  eleccion(cat);
     do{
            do
            {
      			cout<<"Desea seguir Ingresando? [1]SI [2]NO: ";
            	cin>>opc;
            	clrscr();
            }
            while(opc!=1 && opc!=2);
            if(opc==1){
            	eleccion(cat);}else
            {
            	break;
            }
         }while(1);
  }
}
void eleccion(char cat[])
{
   float Desc;
   float Desc1;
   float Bon;
   float Bon1;
   float Bon2;
   p=fopen(cat,"ab");
   Bon1=0;
   Bon2=0;
   Desc1=0;
   cout<<"Ingrese codigo del trabajador :";
   cin>>x.cod;
   cout<<"Ingrese nombre del trabajador :";
   gets(x.nom);
   strcpy(x.cat,cat);
   do
   {
  		cout<<"Ingrese el sexo del trabajador (M/F) :";
  		cin>>x.sex;
   }
   while(strcmp(x.sex,"M")!=0 && strcmp(x.sex,"F")!=0);
   do
   {
   	cout<<"Ingrese el estado civil de trabajador (soltero/casado) :";
   	cin>>x.esci;
   }while(strcmp(x.esci,"soltero")!=0 && strcmp(x.esci,"casado")!=0);
   cout<<"Ingrese la profesion del trabajador :";
   gets(x.pro);
   do
   {
   	cout<<"Ingrese el cargo del trabajador (obrero,administrativo y jefe) :";
   	cin>>x.car;
   }
   while(strcmp(x.car,"obrero")!=0 && strcmp(x.car,"administrativo")!=0 && strcmp(x.car,"jefe")!=0);
   cout<<"Ingrese el sueldo del trabajador :";
   cin>>x.sb;
   do
   {
   	cout<<"Ingrese el bonificacion del trabajador (%):";
   	cin>>Bon;
   }
   while(Desc>100);
   do
   {
   	cout<<"Ingrese el descuento del trabajador (%):";
   	cin>>Desc;
   }
   while(Desc>100);
   if(strcmp(x.car,"obrero")==0)
	{
      do
      {
   		cout<<"Ingrese la bonificacion por vida (%):";
   		cin>>Bon1;
      }
      while(Bon1>100);
	}
	if(strcmp(x.cat,"tecnico")==0)
	{
      do
      {
   		cout<<"Ingrese la bonificacion por capacitacion (%):";
   		cin>>Bon2;
      }
      while(Bon2>100);
	}
	if(strcmp(x.cat,"profesionales")==0)
	{
      do
      {
   	cout<<"Ingrese el descuento del retención de sueldo (%):";
   	cin>>Desc1;
      }
      while(Desc1>100);
	}
   x.DescT=Desc1+Desc;
   x.BonT=Bon1+Bon+Bon2;
   x.Nt=x.sb+((x.sb*x.BonT)/100)-((x.sb*x.DescT)/100);
   cout<<endl;
   fwrite(&x,sizeof(x),1,p);
  fclose(p);
}
void Menu_Mostrar()
{
	int opc1;
   do
   {
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t                 SUBMENU             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Mostrar registros en general     "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Mostrar registros por categoria  "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t3.- Salir                            "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tIngrese su opcion ==> ";
   	cin>>opc1;
   	switch(opc1)
   	{
     		case 1: Mostrar();break;
     		case 2: Mostrar_Cat();break;
      }
   }
   while(opc1<3);
   cout<<endl;
}
void Mostrar_Cat()
{
  int opc=0;

   do
   {
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t                 SUBMENU             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Auxiliar                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Tecnico                          "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Profesional                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t4.- Salir                            "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tIngrese su opcion ==> ";
   	cin>>opc;
   	switch(opc)
   	{
     		case 1:
                {
							char cat[15]="Auxiliar";
	      				Mostrar_Aux(cat);
                    	getch();
   	               break;
                }
     		case 2:
                {
                  char cat[15]="Tecnico";
                  Mostrar_Aux(cat);
                 	getch();
                  break;
                }
         case 3:
                {
                  char cat[15]="Profesional";
         		   Mostrar_Aux(cat);
                  	getch();
                  break;
                }
      }
   }
   while(opc<4);
   cout<<endl;
}
void Mostrar_Aux(char cat[15])
{
 	clrscr();
   bool band;
   band=confirmar(cat);
   if(band==true)
   {
   	p=fopen(cat,"rb");
   	fseek(p,0,SEEK_SET);
	   int a=0;
 		cout<<endl<<endl;
	 	cout<<"------------------------------------------------REGISTRO DE LOS TRABAJADORES--------------------------------------------"<<endl;
      cout<<"N)  Cod.  Nomb.Ap           Cat.        Sexo   Est.Civil   Prof.      Cargo           Sueldo.B  Bonif.  Desc.  Sueldo.N"<<endl;
 	   cout<<"--------|-----------------|-----------|------|-----------|----------|---------------|---------|-------|------|----------"<<endl;
               //4   //10              //28       //40     //47       //59       //70             //86     //96   //104    //111
	  	fread(&x,sizeof(x),1,p);
 		while(!feof(p))
	 	{
  			cout<<(a+1)<<")";
  			gotoxy(5,a+6);cout<<x.cod;
	  		gotoxy(11,a+6);cout<<x.nom;
	  		gotoxy(29,a+6);cout<<x.cat;
  			gotoxy(41,a+6);cout<<x.sex;
  			gotoxy(48,a+6);cout<<x.esci;
	  		gotoxy(60,a+6);cout<<x.pro;
	  		gotoxy(71,a+6);cout<<x.car;
  			gotoxy(87,a+6);cout<<x.sb;
         gotoxy(97,a+6);cout<<x.BonT;
         gotoxy(105,a+6);cout<<x.DescT;
         gotoxy(112,a+6);cout<<x.Nt;
  			cout<<endl;
     		fread(&x,sizeof(x),1,p);
      	a++;
 		}
   	fclose(p);
      cout<<"--------|-----------------|-----------|------|-----------|----------|---------------|---------|-------|------|----------"<<endl;
 		}else{
      	cout<<"No existe informacion previa de la categoria "<<cat<<"\n BUSQUE OTRA CATEGORIA";
      }
      getch();
}
void Mostrar()
{
	int b=0;
   bool band;
 	clrscr();
	char cat[15]="Tecnico";
   band=confirmar(cat);
 	cout<<endl<<endl;
 	cout<<"------------------------------------------------REGISTRO DE LOS TRABAJADORES--------------------------------------------"<<endl;
   cout<<"N)  Cod.  Nomb.Ap           Cat.        Sexo   Est.Civil   Prof.      Cargo           Sueldo.B  Bonif.  Desc.  Sueldo.N"<<endl;
   cout<<"--------|-----------------|-----------|------|-----------|----------|---------------|---------|-------|------|----------"<<endl;
            //4   //10              //28       //40     //47       //59       //70             //86     //96   //104    //111
   if(band==true)
   {
   	p=fopen(cat,"rb");
  	 	fseek(p,0,SEEK_SET);
   	fread(&x,sizeof(x),1,p);
	   while(!feof(p))
   	{
  			cout<<(b+1)<<")";
  			gotoxy(5,b+6);cout<<x.cod;
	  		gotoxy(11,b+6);cout<<x.nom;
	  		gotoxy(29,b+6);cout<<x.cat;
  			gotoxy(41,b+6);cout<<x.sex;
  			gotoxy(48,b+6);cout<<x.esci;
	  		gotoxy(60,b+6);cout<<x.pro;
	  		gotoxy(71,b+6);cout<<x.car;
  			gotoxy(87,b+6);cout<<x.sb;
         gotoxy(97,b+6);cout<<x.BonT;
         gotoxy(105,b+6);cout<<x.DescT;
         gotoxy(112,b+6);cout<<x.Nt;
			cout<<endl;
      	b++;
      	fread(&x,sizeof(x),1,p);
      }
   	fclose(p);
   }
   strcpy(cat,"Auxiliar");
   band=confirmar(cat);
   if(band==true)
   {
     	p=fopen(cat,"rb");
   	fseek(p,0,SEEK_SET);
      fread(&x,sizeof(x),1,p);
	   while(!feof(p))
      {
  			cout<<(b+1)<<")";
  			gotoxy(5,b+6);cout<<x.cod;
	  		gotoxy(11,b+6);cout<<x.nom;
	  		gotoxy(29,b+6);cout<<x.cat;
  			gotoxy(41,b+6);cout<<x.sex;
  			gotoxy(48,b+6);cout<<x.esci;
	  		gotoxy(60,b+6);cout<<x.pro;
	  		gotoxy(71,b+6);cout<<x.car;
  			gotoxy(87,b+6);cout<<x.sb;
         gotoxy(97,b+6);cout<<x.BonT;
         gotoxy(105,b+6);cout<<x.DescT;
         gotoxy(112,b+6);cout<<x.Nt;
			cout<<endl;
      	b++;
      	fread(&x,sizeof(x),1,p);
   	 }
       fclose(p);
   }
   strcpy(cat,"Profesional");
   band=confirmar(cat);
   if(band==true)
   {
  	 	p=fopen(cat,"rb");
   	fseek(p,0,SEEK_SET);
      fread(&x,sizeof(x),1,p);
   	while(!feof(p))
      {
  			cout<<(b+1)<<")";
  			gotoxy(5,b+6);cout<<x.cod;
	  		gotoxy(11,b+6);cout<<x.nom;
	  		gotoxy(29,b+6);cout<<x.cat;
  			gotoxy(41,b+6);cout<<x.sex;
  			gotoxy(48,b+6);cout<<x.esci;
	  		gotoxy(60,b+6);cout<<x.pro;
	  		gotoxy(71,b+6);cout<<x.car;
  			gotoxy(87,b+6);cout<<x.sb;
         gotoxy(97,b+6);cout<<x.BonT;
         gotoxy(105,b+6);cout<<x.DescT;
         gotoxy(112,b+6);cout<<x.Nt;
      	cout<<endl;
      	fread(&x,sizeof(x),1,p);
      	b++;
    	}
    	fclose(p);
   }
   cout<<"--------|-----------------|-----------|------|-----------|----------|---------------|---------|-------|------|----------"<<endl;
 	getch();
}
void eliminar_menu(int E){
   int opc=0;
   do
   {
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t                 SUBMENU             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t Que categoria quisera eliminar    "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t 1.- Auxiliar                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t 2.- Tecnico                          "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t 3.- Profesional                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t 4.- Salir                            "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t ------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t Ingrese su opcion ==> ";
   	cin>>opc;
   	switch(opc)
   	{
     		case 1: {
							char cat[15]="Auxiliar";
	      				Eliminar(cat,E);
   	               break;
                  }
     		case 2:{
	                  char cat[15]="Tecnico";
                  	Eliminar(cat,E);
                     break;
                }
         case 3:{
                 	 	char cat[15]="Profesional";
	         		  	Eliminar(cat,E);
                     break;
                }
      }
   }while(opc<4);
}
void Eliminar(char cat[], int E){
   int opc=0,b;
   bool band=true;
   cout<<"1.- ELiminar todos los datos de la categoria "<<cat<<endl;
   cout<<"2.- ELiminar solo un dato "<<cat<<endl;
   cin>>opc;
   switch(opc)
   {
   	case 1:
      		{
              p=fopen(cat,"wb");
              fclose(p);
              break;
       		}
      case 2:
		      {
            	listar *q,*w=NULL;
            	b=0;
              	Mostrar_Aux(cat);
			   	int a=0,z;
			   	Trabajador aux[100];
               p=fopen(cat,"rb");
           		if(band==true)
               {
               	a=cantidad(cat);
                  cout<<"Que numero del resgistro "<<cat<<" quisiera eliminar: ";
                  cin>>z;
                  while(z>a)
                  {
				     		cout<<"\aEl numero que del registro que quiere eliminar no se encuentra.\nIngrese Nuevamente";cin>>z;
                  }
               	if(E==1)
                  {
                  	p=fopen(cat,"rb");
                     fseek(p,0,SEEK_SET);
			   			fread(aux,sizeof(x),a,p);
                 		for(int i=z-1;i<a;i++){
   							aux[i]=aux[i+1];
			   			}
                     a--;
               		fclose(p);
               		p=fopen(cat,"wb");
               		fwrite(aux,sizeof(x),a,p);
                  	fclose(p);
                  }else{
                     w=NULL;
                  	llenarlista(cat);
                     q=comienzo;
                    	while(b<z-1 && q->sig!=NULL)
                     {
                     	w=q;
                        q=q->sig;
                        b++;
                     }
                     if(w==NULL){
                       comienzo=comienzo->sig;
                  	}else{
                        w->sig=q->sig;
                     }
                     escribirdin(cat);
                  }
               	break;
      			}
            }
	}
}
void modificar_menu(int E){
   int opc=0;
   do
   {
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t                 SUBMENU             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\tQUE CATEGORIA MODIFICARA    "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Auxiliar                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Tecnico                          "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Profesional                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t4.- Salir                            "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tINGRESE OPCION ==> ";
   	cin>>opc;
   	switch(opc)
   	{
     		case 1: {
							char cat[15]="Auxiliar";
	      				Modificar(cat,E);
                     getch();
   	               break;
                  }
     		case 2:{
	                  char cat[15]="Tecnico";
                  	Modificar(cat,E);
                     getch();
                     break;
                }
         case 3:{
                 	 	char cat[15]="Profesional";
	         		  	Modificar(cat,E);
                     getch();
                     break;
                }
      }
   }while(opc<4);

}
void Busqueda(){
	int opc;
   bool band=false;
   char cat[15]="Tecnico";
   Trabajador aux;
   clrscr();
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<" \t\t\t\t\t\t\t\t\tCON RESPECTO A QUE DATO DESEA HACER LA CONSULTA: "<<endl;
   cout<<" \t\t\t\t\t\t\t\t\t                 CORRECCION             "<<endl;
   cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
   cout<<" \t\t\t\t\t\t\t\t\tElija una opcion"<<endl;
	cout<<" \t\t\t\t\t\t\t\t\t1.- Codigo                         "<<endl;
 	cout<<" \t\t\t\t\t\t\t\t\t2.- Nombre Y Apellido              "<<endl;
  	cout<<" \t\t\t\t\t\t\t\t\t3.- Profesion de Trabajo:         "<<endl;
  	cout<<" \t\t\t\t\t\t\t\t\t4.- Cargo                            "<<endl;
   cout<<" \t\t\t\t\t\t\t\t\t5.- Salir              "<<endl;
   cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
 	cout<<" \t\t\t\t\t\t\t\t\tQue elemento quisiera modificar ==> ";
  	cin>>opc;
   switch(opc){
    		case 1:{
          			 char cod[20];
         			 cout<<"Ingrese el codigo a buscar: ";
                   cin>>cod;
                   BusCod(cat,cod,&band);
                   strcpy(cat,"Profesional");
                   BusCod(cat,cod,&band);
                   strcpy(cat,"Auxiliar");
                   BusCod(cat,cod,&band);
                   if(band==true){
                   	cout<<"\t\t\t\t\t\t\t\t  LA BUSQUEDA FUE CORRECTA";
                   }else{
                     clrscr();
         				cout<<"\t\t\t\t\t\t\t\t  NO SE ENCONTRO EL ELEMENTO BUSCADO";
                   }
                   break;
                }
         case 2:{
         			 char nom[20];
                   cout<<"Ingrese el nombre y apellido a buscar: ";
         			 cin>>nom;
                   BusNom(cat,nom,&band);
                   strcpy(cat,"Profesional");
                   BusNom(cat,nom,&band);
                   strcpy(cat,"Auxiliar");
                   BusNom(cat,nom,&band);
                   if(band==true){
                   	cout<<"\t\t\t\t\t\t\t\t  LA BUSQUEDA FUE CORRECTA";
                   }else{
                     clrscr();
         				cout<<"\t\t\t\t\t\t\t\t  NO SE ENCONTRO EL ELEMENTO BUSCADO";
                   }
                   break;
                }
         case 3:{
         			 char pro[20];
         			 cout<<"Ingrese el profesion a buscar: ";
                   cin>>pro;
                   BusPro(cat,pro,&band);
                   strcpy(cat,"Profesional");
                   BusPro(cat,pro,&band);
                   strcpy(cat,"Auxiliar");
                   BusPro(cat,pro,&band);
                   if(band==true){
                   	cout<<"\t\t\t\t\t\t\t\t  LA BUSQUEDA FUE CORRECTA";
                   }else{
                     clrscr();
         				cout<<"\t\t\t\t\t\t\t\t  NO SE ENCONTRO EL ELEMENTO BUSCADO";
                   }
                   break;
                }
         case 4:{
         			char car[20];
         			 cout<<"Ingrese el Cargo a buscar: ";
                   cin>>car;
                   BusCar(cat,car,&band);
                   strcpy(cat,"Profesional");
                   BusCar(cat,car,&band);
                   strcpy(cat,"Auxiliar");
                   BusCar(cat,car,&band);
                   if(band==true){
                   	cout<<"\t\t\t\t\t\t\t\t  LA BUSQUEDA FUE CORRECTA";
                   }else{
                     clrscr();
         				cout<<"\t\t\t\t\t\t\t\t  NO SE ENCONTRO EL ELEMENTO BUSCADO";
                   }
                   break;
                }
    }
   getch();
}
void BusCod(char cat[], char cod[],bool *band){
   bool b=confirmar(cat);
  	if(b==true)
  	{
		p=fopen(cat,"rb");
		while(fread(&x,sizeof(x),1,p)>0){
   		if(strcmp(x.cod,cod)==0){
      		*band=true;
      		datos();
	      }
  		}
  		fclose(p);
	}
}
void BusNom(char cat[], char nom[],bool *band){
  bool b=confirmar(cat);
  if(b==true)
  {
		p=fopen(cat,"rb");
		while(fread(&x,sizeof(x),1,p)>0){
   		if(strcmp(x.nom,nom)==0){
      		*band=true;
      		datos();
	      }
	  }
     fclose(p);
  }
}
void BusCar(char cat[], char car[],bool *band){
  bool b=confirmar(cat);
  if(b==true)
  {
		p=fopen(cat,"rb");
		while(fread(&x,sizeof(x),1,p)>0){
   		if(strcmp(x.car,car)==0){
      		*band=true;
      		datos();
	      }
  		}
      fclose(p);
	}

}
void BusPro(char cat[], char pro[],bool *band){
	bool b=confirmar(cat);
   if(b==true)
   {
		p=fopen(cat,"rb");
		while(fread(&x,sizeof(x),1,p)>0)
   	{
   		if(strcmp(x.pro,pro)==0)
      	{
      		*band=true;
      		datos();
      	}
  		}
  		fclose(p);
   }
}
void datos(){
   clrscr();
   cout<<" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<" \t\t\t\t\t\t\t\t--------DATOS BUSCADO--------"<<endl;
   cout<<" \t\t\t\t\t\t\t\tCODIGO:"<<x.cod<<endl;
   cout<<" \t\t\t\t\t\t\t\tNOMBRE:"<<x.nom<<endl;
   cout<<" \t\t\t\t\t\t\t\tSEXO:"<<x.sex<<endl;;
   cout<<" \t\t\t\t\t\t\t\tESTADO CIVIL:"<<x.esci<<endl;
   cout<<" \t\t\t\t\t\t\t\tPROFESION:"<<x.pro<<endl;
	cout<<" \t\t\t\t\t\t\t\tCARGO:"<<x.car<<endl;
   cout<<" \t\t\t\t\t\t\t\tSUELDO:"<<x.sb<<endl;
	cout<<" \t\t\t\t\t\t\t\tCATEGORIA:"<<x.cat<<endl;
   cout<<" \t\t\t\t\t\t\t\t-----------------------------"<<endl;
}
void Modificar(char cat[], int E)
{
	listar *q,*w;
	int fi,opc,a,b;
   Trabajador aux[2];
   bool ban;
   ban=confirmar(cat);
   clrscr();
   if(ban==true)
   {
     	p=fopen(cat,"rb");
   	a=cantidad(cat);
   	if(a==0)
   	{
    		cout<<" \n\t\t\t\t\t\t\t\t\t\tNO EXISTEN DATOS QUE EN EL REGISTRO QUE MODIFICAR";
         getch();
    		return;
   	}
   	Mostrar_Aux(cat);
   	cout<<"\nCon respecto a que fila quisiera hacer la modificacion: ";
   	cin>>fi;
    	while(fi>a || fi==0)
    	{
 			cout<<"\aEl numero que del registro que quiere modificar no se encuentra.\nIngrese Nuevamente: ";
      	cin>>fi;
	 	}
      clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      cout<<" \t\t\t\t\t\t\t\t\t              CORRECCION             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\tElija una opcion"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Codigo                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Nombre Y Apellido              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Sexo                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t4.- Estado Civil                            "<<endl;
     	cout<<" \t\t\t\t\t\t\t\t\t5.- Profesion de Trabajo:         "<<endl;
    	cout<<" \t\t\t\t\t\t\t\t\t6.- Cargo                            "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t7.- Sueldo de Trabajador              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t8.- Categoria              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t9.- Salir              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tQue elemento quisiera modificar ==> ";
   	cin>>opc;
      clrscr();
    switch(opc)
    {
    		case 1:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      cout<<"Ingrese el codigo nuevo que cambiara: ";
                      cin>>aux[fi-1].cod;
                      p=fopen(cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      cout<<q->li.cod;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      cout<<"Ingrese el codigo nuevo que cambiara: ";
                      cin>>q->li.cod;
                      escribirdin(cat);
                   }
            	    break;
                }
         case 2:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      cout<<"Ingrese el nombre nuevo que cambiara: ";
                      cin>>aux[fi-1].nom;
                      p=fopen(cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      cout<<"Ingrese el nombre nuevo que cambiara: ";
                      cin>>q->li.nom;
                      escribirdin(cat);

                   }
            	    break;
                }
          case 3:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      do
                      {
                        cout<<"Ingrese el sexo nuevo que cambiara: ";
                      	cin>>aux[fi-1].sex;
                        clrscr();
                      }
                      while(strcmp(aux[fi-1].sex,"M")!=0 && strcmp(aux[fi-1].sex,"F")!=0);
                      p=fopen (cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      do
                      {
                        cout<<"Ingrese el sexo nuevo que cambiara: ";
                      	cin>>q->li.sex;
                        clrscr();
                      }
                      while(strcmp(q->li.sex,"M")!=0 && strcmp(q->li.sex,"F")!=0);
                      escribirdin(cat);
                   }
            	    break;
                }
          case 4:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      do
                      {
                        cout<<"Ingrese el estado civil nuevo que cambiara: ";
                      	cin>>aux[fi-1].esci;
                        clrscr();
                      }
                      while(strcmp(aux[fi-1].esci,"soltero")!=0 && strcmp(aux[fi-1].esci,"casado")!=0);
                      p=fopen (cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      do
                      {
                        cout<<"Ingrese el estado civil nuevo que cambiara: ";
                      	cin>>q->li.esci;
                        clrscr();
                      }
                      while(strcmp(q->li.esci,"soltero")!=0 && strcmp(q->li.esci,"casado")!=0);
                      escribirdin(cat);
                   }
            	    break;
                }
          case 5:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      cout<<"Ingrese la profesion nueva que cambiara: ";
                      cin>>aux[fi-1].pro;
                      p=fopen(cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      cout<<"Ingrese la profesion nueva que cambiara: ";
                      cin>>q->li.pro;
                      escribirdin(cat);
                   }
            	    break;
                }
          case 6:
                {
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      do
                      {
                        cout<<"Ingrese el cargo nuevo que cambiara: ";
                      	cin>>aux[fi-1].car;
                        clrscr();
                      }
                      while(strcmp(aux[fi-1].car,"obrero")!=0 && strcmp(aux[fi-1].car,"administrativo")!=0 && strcmp(aux[fi-1].car,"jefe")!=0);
                      p=fopen (cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }
                   else
                   {
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      do
                      {
                        cout<<"Ingrese el cargo nuevo que cambiara: ";
                      	cin>>q->li.car;
                        clrscr();
                      }
                      while(strcmp(q->li.car,"obrero")!=0 && strcmp(q->li.car,"administrativo")!=0 && strcmp(q->li.car,"jefe")!=0);
                      escribirdin(cat);
                   }
            	    break;
                }
          case 7:
                {
                   b=0;
                   if(E==1)
                   {
                      p=fopen(cat,"rb");
  							 fseek(p,0,SEEK_SET);
                      fread(aux,sizeof(x),a,p);
                      fclose(p);
                      cout<<"Ingrese el sueldo nuevo que cambiara: ";
                      cin>>aux[fi-1].sb;
                      p=fopen(cat,"wb");
                      fwrite(aux,sizeof(x),a,p);
						    fclose(p);
                   }else{
                   	 llenarlista(cat);
                      q=comienzo;
                      while(b<fi-1)
                      {
                        q=q->sig;
                        b++;
                      }
                      cout<<"Ingrese el sueldo nuevo que cambiara: ";
                      cin>>q->li.sb;
                      escribirdin(cat);
                   }
            	    break;
                }
           case 8:
                {
                   p=fopen(cat,"rb");
	                fseek(p,((fi-1)*sizeof(x)),SEEK_SET);
   	             fread(&x,sizeof(x),1,p);
      	          fclose(p);
         	       do
            	    {
               	  	cout<<"Ingrese la categoria que cambiara (Auxiliar, Profesional, Tecnico): ";
                 		cin>>x.cat;
               	 }
                	 while(strcmp(x.cat,"Auxiliar")!=0 && strcmp(x.cat,"Profesional")!=0 && strcmp(x.cat,"Tecnico")!=0);
                   p=fopen(x.cat,"ab");
	                fwrite(&x,sizeof(x),1,p);
   	             cout<<"\nREALIZADO EL CAMBIO ";
      	          fclose(p);
                	if(E==1)
	               {
   	               a=cantidad(cat);
    	               p=fopen(cat,"rb");
                     fseek(p,0,SEEK_SET);
                     fread(aux,sizeof(x),a,p);
                 	   for(int i=fi-1;i<a;i++)
                     {
   							aux[i]=aux[i+1];
                     }
                     a--;
	               	fclose(p);
                   	p=fopen(cat,"wb");
                   	fwrite(aux,sizeof(x),a,p);
                   	fclose(p);
                   	break;
                	}else{
                  	b=0;
                     w=NULL;
                     llenarlista(cat);
                     q=comienzo;
                     while(b<fi-1 && q->sig!=NULL)
                     {
                     	w=q;
                        q=q->sig;
                        b++;
                     }
                     if(w==NULL){
                       comienzo=comienzo->sig;
                  	}else{
                        w->sig=q->sig;
                     }
                     escribirdin(cat);
                	}
                  break;
                }
    	}
   }else{
   	cout<<"No existe informacion previa de la categoria "<<cat<<"\n BUSQUE OTRA CATEGORIA";
      getch();
   }
}
void ordenar_menu(int E)
{
	int opc=0;
   do
   {
   	clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<" \t\t\t\t\t\t\t\t\t                 SUBMENU             "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\tQUE CATEGORIA ORDENARA    "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Auxiliar                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Tecnico                          "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Profesional                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t4.- Salir                            "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tIngrese su opcion ==> ";
   	cin>>opc;
   	switch(opc)
   	{
     		case 1:
                {
							char cat[15]="Auxiliar";
	      				Ordenamiento_Eleccion(cat,E);
   	               break;
                }
     		case 2:
                {
	                  char cat[15]="Tecnico";
                  	Ordenamiento_Eleccion(cat,E);
                     break;
                }
         case 3:
                {
                 	 	char cat[15]="Profesional";
	         		  	Ordenamiento_Eleccion(cat,E);
                     break;
                }
      }
   }
   while(opc<4);
}
void escribirdin(char cat[15]){

  p=fopen(cat,"wb");
  fclose(p);
  p=fopen(cat,"ab");
  listar *q=comienzo;
  while(q!=NULL)
  {
    fwrite(q,sizeof(x),1,p);
    q=q->sig;
  }
  cout<<"\t\t\t\t\tEL CAMBIO SE HIZO CORRECTAMENTE";
  fclose(p);
}
listar *llenarin(listar *guardar,listar *dato){
  strcpy(guardar->li.cod,dato->li.cod);
  strcpy(guardar->li.nom,dato->li.nom);
  strcpy(guardar->li.cat,dato->li.cat);
  strcpy(guardar->li.sex,dato->li.sex);
  strcpy(guardar->li.esci,dato->li.esci);
  strcpy(guardar->li.pro,dato->li.pro);
  strcpy(guardar->li.car,dato->li.car);
  guardar->li.sb=dato->li.sb;
  guardar->li.BonT=dato->li.BonT;
  guardar->li.DescT=dato->li.DescT;
  guardar->li.Nt=dato->li.Nt;
  return guardar;
}
void cant(listar *nuevo){
  strcpy(x.cod,nuevo->li.cod);
  strcpy(x.nom,nuevo->li.nom);
  strcpy(x.cat,nuevo->li.cat);
  strcpy(x.sex,nuevo->li.sex);
  strcpy(x.esci,nuevo->li.esci);
  strcpy(x.pro,nuevo->li.pro);
  strcpy(x.car,nuevo->li.car);
  x.sb=nuevo->li.sb;
  x.BonT=nuevo->li.BonT;
  x.DescT=nuevo->li.DescT;
  x.Nt=nuevo->li.Nt;
}
listar *par(listar *nuevo){
  strcpy(nuevo->li.cod,x.cod);
  strcpy(nuevo->li.nom,x.nom);
  strcpy(nuevo->li.cat,x.cat);
  strcpy(nuevo->li.sex,x.sex);
  strcpy(nuevo->li.esci,x.esci);
  strcpy(nuevo->li.pro,x.pro);
  strcpy(nuevo->li.car,x.car);
  nuevo->li.sb=x.sb;
  nuevo->li.BonT=x.BonT;
  nuevo->li.DescT=x.DescT;
  nuevo->li.Nt=x.Nt;
  return nuevo;
}
listar *llenar(listar *nuevo){
  nuevo=(listar *)malloc(tam);
  strcpy(nuevo->li.cod,x.cod);
  strcpy(nuevo->li.nom,x.nom);
  strcpy(nuevo->li.cat,x.cat);
  strcpy(nuevo->li.sex,x.sex);
  strcpy(nuevo->li.esci,x.esci);
  strcpy(nuevo->li.pro,x.pro);
  strcpy(nuevo->li.car,x.car);
  nuevo->li.sb=x.sb;
  nuevo->li.BonT=x.BonT;
  nuevo->li.DescT=x.DescT;
  nuevo->li.Nt=x.Nt;
  nuevo->sig=NULL;
  return nuevo;
}
void llenarlista(char cat[15]){
	comienzo=NULL;
	listar *nuevo, *q;
	p=fopen(cat,"rb");
   fseek(p,0,SEEK_SET);
   while(fread(&x,sizeof(x),1,p)>0)
   {
      nuevo=llenar(nuevo);
      if(comienzo==NULL){
      	comienzo=nuevo;
      }else
      {
      	q=comienzo;
      	while(q->sig!=NULL)
         {
            q=q->sig;
         }
         q->sig=nuevo;
      }
   }
   fclose(p);
}
void Ordenamiento_Eleccion(char cat[],int E)
{
	int opc,a;
   int min;
   Trabajador aux[2];
  	bool band=confirmar(cat);;
   if(band)
   {
   	p=fopen(cat,"rb");
      a=cantidad(cat);
   	if(a==0)
   	{
    		cout<<" \n\t\t\t\t\t\t\t\t\t\tNO EXISTEN DATOS QUE ORDENAR";
      	getch();
    		return;
   	}
      Mostrar_Aux(cat);
      clrscr();
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      cout<<" \t\t\t\t\t\t\t\t\t             ORDENAMIENTO           "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
      cout<<" \t\t\t\t\t\t\t\t\tELIJA UNA OPCION     "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t1.- Codigo                         "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t2.- Nombre Y Apellido              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t3.- Sexo                      "<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\t4.- Estado Civil                            "<<endl;
     	cout<<" \t\t\t\t\t\t\t\t\t5.- Profesion de Trabajo         "<<endl;
    	cout<<" \t\t\t\t\t\t\t\t\t6.- Cargo                            "<<endl;
		cout<<" \t\t\t\t\t\t\t\t\t7.- Sueldo de Trabajador              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t8.- Salir              "<<endl;
      cout<<" \t\t\t\t\t\t\t\t\t------------------------------------"<<endl;
   	cout<<" \t\t\t\t\t\t\t\t\tQue elemento quisiera modificar ==> ";
   	cin>>opc;
    switch(opc)
    {
    		case 1:
               {
               	if(E==1)
                  {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].cod,aux[min].cod)<0))
                        {
                        	min=j;
                        }
                     }
                     x=aux[i];
                     aux[i]=aux[min];
                     aux[min]=x;
                   }
                  	 p=fopen(cat,"wb");
                   	fwrite(aux,sizeof(x),a,p);
                   	fclose(p);
                   }else{
                   		listar *q,*l;
                        llenarlista(cat);
                        q=comienzo;
                        while(q!=NULL){
                          l=q->sig;
                          while(l!=NULL){
                            if(strcmp(l->li.cod,q->li.cod)<0){
                            		cant(l);
                                 l=llenarin(l,q);
                                 q=par(q);
                            }
                            l=l->sig;
                          }
                           q=q->sig;
                        }
                        escribirdin(cat);
                   }
                   break;
                }
         case 2:
                {
                  if(E==1)
                  {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].nom,aux[min].nom)<0))
                        {
                        	min=j;
                        }
                     }
                   	x=aux[i];
                     aux[i]=aux[min];
                     aux[min]=x;
                   }
                   	p=fopen(cat,"wb");
                   	fwrite(aux,sizeof(x),a,p);
                   	fclose(p);
                   }else{
                   		listar *q,*l;
                        llenarlista(cat);
                        q=comienzo;
                        while(q!=NULL){
                          l=q->sig;
                          while(l!=NULL){
                            if(strcmp(l->li.nom,q->li.nom)<0){
                            		cant(l);
                                 l=llenarin(l,q);
                                 q=par(q);
                            }
                            l=l->sig;
                          }
                           q=q->sig;
                        }
                        escribirdin(cat);
                   }
                   break;
                }
         case 3:
                {
                 if(E==1)
                 {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].sex,aux[min].sex)<0))
                        {
                        	min=j;
                        }
                     }
                     x=aux[i];
                     aux[i]=aux[min];
                     aux[min]=x;
                   }
                   p=fopen(cat,"wb");
                   fwrite(aux,sizeof(x),a,p);
                   fclose(p);
                 }else{
                    listar *q,*l;
                    llenarlista(cat);
                    q=comienzo;
                    while(q!=NULL){
                    	l=q->sig;
                    		while(l!=NULL){
                    			if(strcmp(l->li.sex,q->li.sex)<0){
                        		cant(l);
                        		l=llenarin(l,q);
                        		q=par(q);
                           }
                           l=l->sig;
                          }
                          q=q->sig;
                        }
                     escribirdin(cat);
                 }
                   break;
                }
         case 4:
                {
                 if(E==1)
                 {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].esci,aux[min].esci)<0))
                        {
                        	min=j;
                        }
                     }
                     x=aux[i];
                     aux[i]=aux[min];
                     aux[min]=x;
                   }
                   p=fopen(cat,"wb");
                   fwrite(aux,sizeof(x),a,p);
                   fclose(p);
                   }else{
                    listar *q,*l;
                    llenarlista(cat);
                    q=comienzo;
                    while(q!=NULL){
                    	l=q->sig;
                    		while(l!=NULL){
                    			if(strcmp(l->li.esci,q->li.esci)<0){
                        		cant(l);
                        		l=llenarin(l,q);
                        		q=par(q);
                           }
                           l=l->sig;
                          }
                          q=q->sig;
                        }
                     escribirdin(cat);
                   }
                   break;
                }
         case 5:
                {
                 if(E==1)
                 {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].pro,aux[min].pro)<0))
                        {
                        	min=j;
                        }
                     }
                     x=aux[i];
                     aux[i]=aux[min];
                     aux[min]=x;
                   }
                   p=fopen(cat,"wb");
                   fwrite(aux,sizeof(x),a,p);
                   fclose(p);
                   }else{
                    listar *q,*l;
                    llenarlista(cat);
                    q=comienzo;
                    while(q!=NULL){
                    	l=q->sig;
                    		while(l!=NULL){
                    			if(strcmp(l->li.pro,q->li.pro)<0){
                        		cant(l);
                        		l=llenarin(l,q);
                        		q=par(q);
                           }
                           l=l->sig;
                          }
                          q=q->sig;
                        }
                     escribirdin(cat);
                   }
                   break;
                }
         case 6:
                {
                 if(E==1)
                 {
         			 p=fopen(cat,"rb");
                   fseek(p,0,SEEK_SET);
                   fread(aux,sizeof(x),a,p);
                   fclose(p);
                   for(int i=0;i<a;i++)
                   {
                   	min=i;
                     for(int j=i+1;j<a;j++)
                     {
                     	if((strcmp(aux[j].car,aux[min].car)<0))
                        {
                        	min=j;
                        }
                     }
                     x=aux[i];
 						   aux[i]=aux[min];
					      aux[min]=x;

                   }
                   p=fopen(cat,"wb");
                   fwrite(aux,sizeof(x),a,p);
                   fclose(p);
                   }else{
                    listar *q,*l;
                    llenarlista(cat);
                    q=comienzo;
                    while(q!=NULL){
                    	l=q->sig;
                    		while(l!=NULL){
                    			if(strcmp(l->li.car,q->li.car)<0){
                        		cant(l);
                        		l=llenarin(l,q);
                        		q=par(q);
                           }
                           l=l->sig;
                          }
                          q=q->sig;
                        }
                     escribirdin(cat);
                   }
                   break;
                }
         case 7:
                {
                 if(E==1)
                 {
         		   p=fopen(cat,"rb");
                  fseek(p,0,SEEK_SET);
                  fread(aux,sizeof(x),a,p);
                  fclose(p);
                  for(int i=0;i<a;i++)
                  {
                 		min=i;
                    for(int j=i+1;j<a;j++)
                    {
                    	if(aux[j].sb<aux[min].sb)
                     {
	                    	min=j;
                     }
                    }
	                  x=aux[i];
						   aux[i]=aux[min];
					      aux[min]=x;
                  }
                  p=fopen(cat,"wb");
                  fwrite(aux,sizeof(x),a,p);
                  fclose(p);
                  }else{
                    listar *q,*l;
                    llenarlista(cat);
                    q=comienzo;
                    while(q!=NULL){
                    	l=q->sig;
                    		while(l!=NULL){
                    			if(l->li.sb < q->li.sb){
                        		cant(l);
                        		l=llenarin(l,q);
                        		q=par(q);
                           }
                           l=l->sig;
                          }
                          q=q->sig;
                        }
                     escribirdin(cat);
                   }
                  break;
                }

     }
     if(opc<7)
     {
    	 cout<<" \t\t\t\t\t\t\t\t\t\tSE ORDENO CORRECTAMENTE"<<endl;
     }
    }else{
    	cout<<"No existe informacion previa de la categoria "<<cat<<"\n BUSQUE OTRA CATEGORIA";
   }
}

