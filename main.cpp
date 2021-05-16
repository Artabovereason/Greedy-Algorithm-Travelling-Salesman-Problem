#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <array>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

#define town_number 10

double fact(int n){

     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

double distance_town(array<double, 2>   a, array<double, 2>  b)
{
return hypot(b[0]-a[0], b[1]-a[1]);
}

double travllingSalesmanProblem(double matrix[town_number][town_number], int s, array<array<double, 2>,town_number> towns,clock_t t)
{


vector<double> longueur_chemin;

vector<double> vertex;
for (int i = 0; i < town_number; i++)
        if (i != s)
            vertex.push_back(i);

  double min_path = INT_MAX;
  do
  {

    double current_pathweight = 0;

    int k = s;

    for (int i = 0; i < vertex.size(); i++)
    {
      longueur_chemin.push_back(k);
      int A= vertex[i];
      current_pathweight += matrix[k][A];
      k = vertex[i];
      if (int j=i == vertex.size()-1)
      {
        longueur_chemin.push_back(k);
      }
    }
    t=(clock() - t);
    float temps =((float)t)/CLOCKS_PER_SEC;

/*
 if ( temps>0.05 && temps <3){
    //  cout<<((float)t)/CLOCKS_PER_SEC<<endl;
      cout<<"Le programme de ses morts run en "<< (2*temps/((longueur_chemin.size()/fact(town_number))))<<"secondes"<<endl;
     break;
   }
*/


    current_pathweight += matrix[k][s];
    longueur_chemin.push_back(current_pathweight);


    min_path = min(min_path, current_pathweight);

  }
  while(
    next_permutation(vertex.begin(), vertex.end()));


for (int i =town_number; i< longueur_chemin.size();i=i+town_number+1)
{
  //cout<<longueur_chemin[i]<<endl;
    if (longueur_chemin[i]==min_path)
  {
      //cout<<"Le chemin suivi est alors : "<<longueur_chemin[i-4]<<" "<<longueur_chemin[i-3]<<" "<<longueur_chemin[i-2]<<" "<<longueur_chemin[i-1]<<endl;
      ofstream optimal_path("optimal_path.txt");
    for (int j =i-town_number; j<i;j++ )
    {
         if (j+1==i){
        optimal_path<<towns[longueur_chemin[j]][0]<<" "<<towns[longueur_chemin[j]][1]<<" "<<towns[longueur_chemin[i-town_number]][0]<<" "<<towns[longueur_chemin[i-town_number]][1]<<endl;
        }
        else{
          optimal_path<<towns[longueur_chemin[j]][0]<<" "<<towns[longueur_chemin[j]][1]<<" "<<towns[longueur_chemin[j+1]][0]<<" "<<towns[longueur_chemin[j+1]][1]<<endl;}

    }
  }

}
cout<<longueur_chemin.size()<<endl;
  return min_path;
}

double travllingSalesmanProblemMax(double matrix[town_number][town_number], int s, array<array<double, 2>,town_number> towns,clock_t t)
{


vector<double> longueur_chemin_max;

vector<double> vertex;
for (int i = 0; i < town_number; i++)
        if (i != s)
            vertex.push_back(i);

  double max_path = INT_MIN;
  do
  {

    double current_pathweight = 0;

    int k = s;

    for (int i = 0; i < vertex.size(); i++)
    {
      longueur_chemin_max.push_back(k);
      int A= vertex[i];
      current_pathweight += matrix[k][A];
      k = vertex[i];
      if (int j=i == vertex.size()-1)
      {
        longueur_chemin_max.push_back(k);
      }
    }
    t=(clock() - t);
    float temps =((float)t)/CLOCKS_PER_SEC;

/*
 if ( temps>0.05 && temps <3){
    //  cout<<((float)t)/CLOCKS_PER_SEC<<endl;
      cout<<"Le programme de ses morts run en "<< (2*temps/((longueur_chemin.size()/fact(town_number))))<<"secondes"<<endl;
     break;
   }
*/


    current_pathweight += matrix[k][s];
    longueur_chemin_max.push_back(current_pathweight);


    max_path = max(max_path, current_pathweight);

  }
  while(
    next_permutation(vertex.begin(), vertex.end()));


for (int i =town_number; i< longueur_chemin_max.size();i=i+town_number+1)
{
  //cout<<longueur_chemin[i]<<endl;
    if (longueur_chemin_max[i]==max_path)
  {
      //cout<<"Le chemin suivi est alors : "<<longueur_chemin[i-4]<<" "<<longueur_chemin[i-3]<<" "<<longueur_chemin[i-2]<<" "<<longueur_chemin[i-1]<<endl;
      ofstream optimal_path_max("optimal_pathmax.txt");
    for (int j =i-town_number; j<i;j++ )
    {
         if (j+1==i){
        optimal_path_max<<towns[longueur_chemin_max[j]][0]<<" "<<towns[longueur_chemin_max[j]][1]<<" "<<towns[longueur_chemin_max[i-town_number]][0]<<" "<<towns[longueur_chemin_max[i-town_number]][1]<<endl;
        }
        else{
          optimal_path_max<<towns[longueur_chemin_max[j]][0]<<" "<<towns[longueur_chemin_max[j]][1]<<" "<<towns[longueur_chemin_max[j+1]][0]<<" "<<towns[longueur_chemin_max[j+1]][1]<<endl;}

    }
  }

}
cout<<longueur_chemin_max.size()<<endl;
  return max_path;
}

double findMax(double mat[town_number][town_number])
{

    double maxElement = INT_MIN;

    for (int i = 0; i < town_number; i++)
    {
        for (int j = 0; j < town_number; j++)
        {
            if (mat[i][j] > maxElement)
            {
                maxElement = mat[i][j];
            }
        }
    }

    return maxElement;
}

double findMean(double a[town_number][town_number])
{
    double sum = 0;

    for (int i=0; i<town_number; i++)
       for (int j=0; j<town_number; j++)
          sum += a[i][j];

    return (double)sum/(town_number*town_number);
}




int main()
{

  array<array<double, 2>,town_number> towns =
  {
    array<double, 2>
    {{ 2, 2 }},
    {{ 3, 5 }},
    {{ 7, 2 }},
    {{ -10, 21 }},
    {{ -2, 4 }},
    {{ -12, 4 }},
    {{ 5, 4 }},
    {{ 12, 3 }},
    {{ 4, 8 }},
    {{ 17, -2 }}/*,
    {{ -3, -4 }},
    {{ 7, -4 }},
    {{ -8, 4 }},
    {{ 15, -9 }},
    {{ 3, 2 }},
    {{ 3, 4 }},
    {{ 7, 12 }},
    {{ 13, -3 }},
    {{ -9, -4 }},
    {{ -1, 4 }}*/ //20
  };



double matrix[town_number][town_number];


for ( int i = 0; i < town_number; i++ )
      for ( int j = 0; j < town_number; j++ )
      {
matrix[i][j]=distance_town(towns[i], towns[j]) ;
      }


array<string,10> name_town = {"Paris","Moscou","Strasbourg","Dijon","Toulouse","Montpellier","Rennes","Marseille","Berlin","Brest"};

ofstream coordonnee("coordonnee.txt");
for (int i =0;i<town_number;i++)
{
      coordonnee<<towns[i][0]<<" "<<towns[i][1]<<" "<<name_town[i]<<endl;
}

ofstream coordonnee_bloc("coordonnee_bloc.txt");
for ( int j = 0; j < town_number; j++ )
{
    for (int i =0;i<town_number;i++)
    {
      coordonnee_bloc<<towns[j][0]<<" "<<towns[j][1]<<" "<<towns[(i+1)%town_number][0]<<" "<<towns[(i+1)%town_number][1]<<endl;
    }
coordonnee_bloc<<" "<<endl;
coordonnee_bloc<<" "<<endl;
}

clock_t t;
int s = 0;
t = clock();

cout << travllingSalesmanProblem(matrix, s,towns,t) << endl;
  t = clock() - t;
printf ("It took me %d clicks for min (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

cout << travllingSalesmanProblemMax(matrix, s,towns,t) << endl;
  t = clock() - t;
printf ("It took me %d clicks for max(%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
double sum0=0;
for(int i = 0; i < town_number; i++){
   sum0 += towns[i][0];
}
double xmean =  sum0 / town_number;

double sum1=0;
for(int i = 0; i < town_number; i++){
   sum1 += towns[i][1];
}
double ymean =  sum1 / town_number;

cout<<xmean<<" "<<ymean<<" "<< findMax(matrix)<<endl;

/*
ofstream town_graphic("town_graphic.gnu");
   town_graphic<<"set offset 1,1,1,1"<<endl;
   town_graphic<<"set style fill transparent solid 0.5"<<endl;
   town_graphic<<"set xrange ["<<xmean-findMax(matrix)/1.3<<":"<<xmean+findMax(matrix)/1.3<<"]"<<endl;
   //town_graphic<<"set xtics font \"Verdana,15\""<<endl;
   town_graphic<<"set yrange ["<<ymean-findMax(matrix)/1.3<<":"<<ymean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic<<"plot 'coordonnee.txt' using 1:2:3 with labels point  pt 7 offset char 0.5,0.5 notitle , \"coordonnee_bloc.txt\" using 1:2:($3-$1):($4-$2) with vectors nohead, 'optimal_path.txt' using 1:2:($3-$1):($4-$2) with vectors nohead linecolor rgb \"red\" "<<endl; // \"coordonnee_bloc.txt\" using 1:2:($3-$1):($4-$2) with vectors nohead,
   //town_graphic<<"plot 'coordonnee.txt' with points pt 7"<<endl;
   town_graphic<< "pause -1" <<endl;
   town_graphic<<"set terminal postscript eps size 3.5,2.62 enhanced color"<<endl;
   town_graphic<<"set output \"carte.eps\""<<endl;
   town_graphic<<"replot"<<endl;
   system("gnuplot town_graphic.gnu");
*/


ofstream town_graphic_multi("town_graphic_multi.gnu");
town_graphic_multi<<"set terminal postscript eps size 7,5.24 enhanced color"<<endl;
town_graphic_multi<<"set output \"cartefull.eps\""<<endl;
   town_graphic_multi<<"set multiplot layout 2,2 rowsfirst"<<endl;
   town_graphic_multi<<"set key font \"Verdana,12\""<<endl;
   town_graphic_multi<<"set xtics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set ytics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set title \"Representation de l'Univers \" font \"Verdana,13\""<<endl;
   town_graphic_multi<<"set xlabel \"x\""<<endl;
   town_graphic_multi<<"set xrange ["<<xmean-findMax(matrix)/1.3<<":"<<xmean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set ylabel \"y\""<<endl;
   town_graphic_multi<<"set yrange ["<<ymean-findMax(matrix)/1.3<<":"<<ymean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set style fill transparent solid 0.2 noborder"<<endl;
   town_graphic_multi<<"plot 'coordonnee.txt' using 1:2:3 with labels point  pt 7 offset char 0.5,0.5 notitle"<<endl;

   town_graphic_multi<<"set key font \"Verdana,12\""<<endl;
   town_graphic_multi<<"set xtics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set ytics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set title \"Representation de tous les chemins\""<<endl;
   town_graphic_multi<<"set xlabel \"x\""<<endl;
   town_graphic_multi<<"set xrange ["<<xmean-findMax(matrix)/1.3<<":"<<xmean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set ylabel \"y point\""<<endl;
   town_graphic_multi<<"set yrange ["<<ymean-findMax(matrix)/1.3<<":"<<ymean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set style fill transparent solid 0.2 noborder"<<endl;
   town_graphic_multi<<"plot \"coordonnee_bloc.txt\" using 1:2:($3-$1):($4-$2) with vectors nohead  linecolor rgb \"grey\"  title \"Chemins\",'coordonnee.txt' with points pt 7 title \"ville\" "<<endl;

   town_graphic_multi<<"set key font \"Verdana,12\""<<endl;
   town_graphic_multi<<"set xtics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set ytics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set title \"Representation du chemin optimal\""<<endl;
   town_graphic_multi<<"set xlabel \"x\""<<endl;
   town_graphic_multi<<"set xrange ["<<xmean-findMax(matrix)/1.3<<":"<<xmean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set ylabel \"y\""<<endl;
   town_graphic_multi<<"set yrange ["<<ymean-findMax(matrix)/1.3<<":"<<ymean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set style fill transparent solid 0.2 noborder"<<endl;
   town_graphic_multi<<"plot 'optimal_path.txt' using 1:2:($3-$1):($4-$2) with vectors nohead linecolor rgb \"blue\" title \"Chemin optimal\",'coordonnee.txt' with points pt 7 title \"ville\""<<endl;

   town_graphic_multi<<"set key font \"Verdana,12\""<<endl;
   town_graphic_multi<<"set xtics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set ytics font \"Verdana,15\""<<endl;
   town_graphic_multi<<"set title \"Representation du chemin maximal\""<<endl;
   town_graphic_multi<<"set xlabel \"x\""<<endl;
   town_graphic_multi<<"set xrange ["<<xmean-findMax(matrix)/1.3<<":"<<xmean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set ylabel \"y\""<<endl;
   town_graphic_multi<<"set yrange ["<<ymean-findMax(matrix)/1.3<<":"<<ymean+findMax(matrix)/1.3<<"]"<<endl;
   town_graphic_multi<<"set style fill transparent solid 0.2 noborder"<<endl;
   town_graphic_multi<<"plot 'optimal_pathmax.txt' using 1:2:($3-$1):($4-$2) with vectors nohead linecolor rgb \"red\" title \"Chemin maximal\",'coordonnee.txt' with points pt 7 title \"ville\""<<endl;

   town_graphic_multi<<"pause -1"<<endl; // le graphique reste affiché tant que je ne le ferme pas

   town_graphic_multi<<"replot"<<endl;
   system("gnuplot town_graphic_multi.gnu");





}
