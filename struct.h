
//struct

//------------------------------
struct data
{
    int dia;
    int mes;
    int ano;
};

struct hora
{
    int hora;
    int minuto;
};

struct funcionario
{
    int codigo;
    char nome[30];
    struct data idade;
    int dependentes;
    char nivel; // B-basico,M-media,S-superior
    struct hora hrEntrada;
    struct hora hrSaida;
    int horasExtras;
    float salario;
};

//-----------------------------------------
