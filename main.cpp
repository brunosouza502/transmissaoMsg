/* 
 * File:   main.cpp
 * Author: Bruno
 *
 * Created on 6 de Junho de 2014, 02:51
 */

#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//alguns testes antes
void automatoDoArquivo(string);
void automatoSep(string, int);//separador

void automatoDoArquivo(string token)
{
	cout<<token<<endl;
	int pos=0;
	int estado=1;
	int sizeEstado;//estado do automato que se define o tamanho/numero de bits da msg
	for(int i=0;i<token.length() && estado!=0;i++)
	{
		switch(estado){
			case 1: {
				estado = 0;
                                //cout<<i;
				if(token[i]=='0')
					estado = 2;//init
				cout<<"pos"<<i<<":"<<token[i]<<" ";
                break;
			}

			case 2: {//init
				if(token[i]=='0')
					estado = 3;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
                break;
			}
			//size: começa a ler o tamanho
			case 3: {
				if(token[i]=='0' )//size de 1 a 3 (001 a 011)
					estado = 4;
				else
					if(token[i]=='1')
						estado = 16;
                cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 4:{
				if(token[i]=='0' )
					estado = 5;
				else
					if(token[i]=='1')
						estado = 8;
                cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 5: {
				if(token[i]=='1')
					estado = 6;//size1
				else//pode indicar size = 000
					if(token[i]=='0')
						estado = 45;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 6: {//msg
				if(token[i]=='0' || token[i]=='1')
					estado = 7;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 7: {//size1 agora vai para o separador
				if(token[i]=='1')
					estado = 46;//separador se tiver mais msg
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 8: {
				if(token[i]=='0')
					estado = 9;//size2
				else
					if(token[i]=='1')
						estado = 12;//size3
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			} 

			case 9: {
				if(token[i]=='0' || token[i]=='1')
					estado = 10;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 10: {
				if(token[i]=='0' || token[i]=='1')
					estado = 11;//msg com tamaho 2
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 11: {//msg com tamanho 2 agora vai para o separador
				if(token[i]=='1')
					estado = 46;//separador se tiver mais de duas msg
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 12: {
				if(token[i]=='0' || token[i]=='1')
					estado = 13;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 13: {
				if(token[i]=='0' || token[i]=='1')
					estado = 14;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 14: {
				if(token[i]=='0' || token[i]=='1')
					estado = 15;//msg com tamanho 3 agora vai para o separador
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 15: {//msg com tamanho 3 agora vai para o separador
				if(token[i]=='0' || token[i]=='1')
					estado = 46;//separador
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 16: {
				if(token[i]=='0')
					estado = 17;
				else
					if(token[i]=='1')
						estado = 29;
				cout<<"pos"<<i<<":"<<token[i]<<" "<<"Estado 17 ";
				break;
			}

			case 17: {
				if(token[i]=='0')
					estado = 18;//size4
				else
					if(token[i]=='1')
						estado = 23;//size5
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 18: {//size4
				if(token[i]=='0' || token[i]=='1')
					estado = 19;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;

			case 19: {
				if(token[i]=='0' || token[i]=='1')
					estado = 20;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 20: {
				if(token[i]=='0' || token[i]=='1')
					estado = 21;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 21: {
				if(token[i]=='0' || token[i]=='1')
					estado =22 ;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 22: {//msg com tamanho 4 (bits) agora vai para o separador
				if(token[i]=='0' || token[i]=='1')
					estado = 46;//começa o separador se tem mais de uma msg
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 23: {//size5
				if(token[i]=='0' || token[i]=='1')
					estado = 24;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 24: {
				if(token[i]=='0' || token[i]=='1')
					estado = 25;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 25: {
				if(token[i]=='0' || token[i]=='1')
					estado = 26;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 26: {
				if(token[i]=='0' || token[i]=='1')
					estado =27 ;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 27: {
				if(token[i]=='0' || token[i]=='1')
					estado = 28;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 28: {//msg com tamanho 5 (bits) agora vai para o separador
				if(token[i]=='1')//(token[i]=='0' || token[i]=='1')
					estado = 46;//separador se tiver mais de duas msg
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 29: {//definindo tamanho da msg
				if(token[i]=='0')
					estado = 30;//vai pra size6
				else
					if(token[i]=='1')
						estado = 37;//vai pra size7
				cout<<"pos"<<i<<":"<<token[i]<<" "<<"Estado 17 ";
				break;
			}

			case 30: {//size6
				if(token[i]=='0' || token[i]=='1')
					estado = 31;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 31: {
				if(token[i]=='0' || token[i]=='1')
					estado = 32;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 32: {
				if(token[i]=='0' || token[i]=='1')
					estado = 33;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 33: {
				if(token[i]=='0' || token[i]=='1')
					estado = 34;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 34: {
				if(token[i]=='0' || token[i]=='1')
					estado = 35;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 35: {
				if(token[i]=='0' || token[i]=='1')
					estado = 36;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 36: {//msg de tamanho 6 bits agora vai para o separador 
				if(token[i]=='1')
					estado = 46;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 37: {//fazendo size7
				if(token[i]=='0' || token[i]=='1')
					estado = 38;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 38: {//fazendo size7
				if(token[i]=='0' || token[i]=='1')
					estado = 39;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 39: {
				if(token[i]=='0' || token[i]=='1')
					estado = 40;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 40 : {//size 7 ainda
				if(token[i]=='0' || token[i]=='1')
					estado = 41;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 41: {//size 7 ainda
				if(token[i]=='0' || token[i]=='1')
					estado = 42;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 42: {
				if(token[i]=='0' || token[i]=='1')
					estado = 43;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 43: {
				if(token[i]=='0' || token[i]=='1')
					estado = 44;//msg de tamanho 7 bits vai pra end ou para separador 
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 44: {
				if(token[i]=='0' || token[i]=='1')
					estado = 46;//vai para separador ou end
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 45: {//indicou size = 000 agora está formando o separador
				if(token[i]=='1')
					estado = 93;//está formando o separador
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			//SEPARADOR de msg ou END se tiver 1 msg apenas
			case 46: {//separador se tiver mais msg
				if(token[i]=='0')
					estado = 48;//vai para separador agora
				else
				if(token[i]=='1')
					estado = 47;//end finaliza msg
				cout<<"pos"<<i<<":"<<token[i]<<" "<<"Estado: "<<estado;
				break;

			}

			case 47: {
				if(token[i]=='0' || token[i]=='1')
					estado = 0;//possui caracteres depois de end, então cadeia não é válida
				cout<<"Estado extrapolado";
				break;
			}

			case 48: {
				if(token[i]=='1')
					estado = 49;//separador agora pode formar outra msg
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 49: {//pode formar outra msg, voltando no automato
				if(token[i]=='0')
					estado = 4;
				else
					if(token[i]=='1')
						estado = 16;
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			case 93: {//ainda está formando o separador; size 000 foi indicado na primeira mensagem
				if(token[i]=='0')
					estado = 48;//vai para o zero do separador
				cout<<"pos"<<i<<":"<<token[i]<<" ";
				break;
			}

			}
        }
	}
        cout<<"estado: "<<estado;
        if(estado == 47)
        	cout<<endl<<" TRANSMISSAO VALIDA ";
        else
        	cout<<endl<<" TRANSMISSAO INVALIDA ";
}

void lerArquivo()
{
	int pos = 0;
	string transmissao;
	string str = " ";
	std::ifstream is("entrada.txt");

	while(is.good())
	{
		char c = is.get();
		if(is.good())
			transmissao.insert(transmissao.end(),c);
	}
	is.close();
	automatoDoArquivo(transmissao);
}

void lerEntrada()
{
	string transmissao;
	char digito;
	cout<<"Digite a transmissao inteira, pressione 'f' quando terminar"<<endl<<"Formato de transmissao: "<<endl<<"init size msg sep size msg end"<<endl;
	do{
		cin>>digito;
		if(digito=='0' || digito=='1')
			transmissao.insert(transmissao.end(),digito);
	}while(digito!='f');
	cout<<endl<<transmissao<<endl;
	automatoDoArquivo(transmissao);
}

int main()
{
	char op;
	cout<<"Fornecer entrada? (s/n): "<<endl;
	do{
		cin>>op;
		if(op=='n'){
			cout<<"Fim";
			exit(1);
		}
		else
			lerEntrada();
		cout<<" Mais alguma transmissao? (s/n): ";
	}while(op);
	//lerEntrada();
    //lerArquivo();
}


