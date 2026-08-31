#pragma once
#include <string>
using namespace std;
class Cancha {
private:
	string Codigo;
	string TipoDeporte;
	char franjas[12];
	float precio;
public:
	Cancha();
	Cancha(string Codigo, string TipoDeporte, float precio);
	string getCodigo();
	string getTipoDeporte();
	float getPrecio();
	char getFranja(int posicion);
	void setPrecio(float precio);
	void setFranja(int posicion, char estado);
};