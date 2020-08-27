#include <stdio.h>
#include <string.h>
#include <regex.h>

struct Asset {
    char name[64];
    char last_name[64];
    char id[14];
};

struct Agent {
    char name[64];
    char last_name[64];
    int age;
    char gender;
    struct Asset asset[10];
    char mission[12];
};

//Globales
struct Agent agents[10];
struct Asset assets[100];
char mission[64][12];

//Registers
void registerAgent(){
    
}

void registerMission(char mis[12]){
    
}

//Check if mission exists
void checkMission(){
    //if mission in mission
}

int checkName(char name[64]) {
    regex_t reg;
    int value;
    regcomp(&reg, "^[A-Z]{1}[a-z]+$", REG_EXTENDED);
    value = regexec(&reg, name, 0, NULL, 0);
    if (value != 0) {
        printf("Invalid name. Try again\n");
    }
    regfree(&reg);
    return value;
}


int main() {
    struct Agent agent;
    regex_t regex;
    int return_value;
    short int num;
    int iAsset = 0;
    int iAgent = 0;
    int iMission = 0;
    char a_id[64];
    char mission[12];
    short int noAsset;
    char new_mission[12];
    struct Asset asset;
    
    do {
        printf( "Select your task:\n 1. Add a new agent \n 2. Add a new asset \n 3. Add a new mission \n 4. Quit");
        scanf("%hd", &num);
        switch (num) {
            case 1:
                // Registrar agente
                printf("You have chosen to add a new agent. \n Please enter the following information:\n");
                printf("First name:\n");
                scanf("%s", agent.name);
                while(checkName(agent.name) != 0){
                    scanf("%s", agent.name);
                }


                printf("Last name:\n");
                scanf("%s", agent.last_name);
                while(checkName(agent.last_name) != 0){
                    scanf("%s", agent.last_name);
                }
                
                printf("Age:\n");
                scanf("%d", &agent.age);
                
                printf("Gender (M/F):\n");
                scanf(" %c", &agent.gender);
                while (agent.gender != 'M' && agent.gender != 'F') {
                    printf("Invalid gender. Try again\n");
                    scanf(" %c", &agent.gender);
                }
                
                printf("How many assets will you be adding?\n");
                scanf("%hd", &noAsset);
                
                for (short int i = 0; i < noAsset; i++) {
                    printf("Please enter the AssetID\n");
                    scanf("%s", a_id);
                    //registerAsset(a_id);
                }
        
                printf("Enter a mission: \n");
                scanf("%s", mission);
                //checkMission();
                //registerMission(mission);
                
                break;

            case 2:
                // Registrar mision
                printf("You have selected to register a mission. Please enter the ID mission:");
                scanf("%s", new_mission);
                // agregar la misión al arreglo de arreglos
                registerMission(new_mission);
                break;
            
            case 3:
                // Pedir datos de asset
                printf("First name: ");
                scanf("%s", asset.name);
                while(checkName(asset.name) != 0){
                    scanf("%s", asset.name);
                }
                
                printf("Last name: ");
                scanf("%s", asset.last_name);
                while(checkName(asset.last_name) != 0){
                    scanf("%s", asset.last_name);
                }
                
                printf("Asset ID: ");
                scanf("%s", asset.id);
                
                regcomp(&regex, "[A-Za-z]{4}[0-9]{9}", REG_EXTENDED);
                return_value = regexec(&regex, asset.id, 0, NULL, 0);

                
                // si se encontró el patrón
                if (return_value == 0) {
                    // registro
                    assets[iAsset] = asset;
                    iAsset++;
                }
                else if (return_value == REG_NOMATCH) {
                    printf("ID invalido\n");
                }
                else{
                    printf("ERROR\n");
                }
                break;
            
            case 4:
                //Salir del programa
                break;
            

            default:
                printf("Invalid option. Try again.");
                break;
        }
        
    } while(num!=4);
    printf( "Thank you for using this application. Good luck on your mission. The Secretary is counting on you." );
    return 0;
}
