#include <stdio.h>
#include <string.h>
#include <regex.h>

struct Asset {
    char name[64];
    char last_name[64];
    char id[13];
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

void registerMission(char mis){
    
}

//Check if mission exists
void checkMission(){
    //if mission in mission 
}



int main() {
    regex_t regex;
    int return_value;
	short int num;
    int iAsset = 0;
    int iAgent = 0;
	int iMission = 0;
	
	do {
        printf( "Select your task:\n 1. Add a new agent \n 2. Add a new asset \n 3. Add a new mission \n 4. Quit");
        scanf("%d", num);
        switch (num) {
            case 1:
                // Registrar agente
                struct Agent agent;
                char a_id[64];
                char mission[12];
                short int noAsset;
                
                printf("You have chosen to add a new agent. \n Please enter the following information:\n");
                printf("First Name:\n");
                scanf("%s", agent.name);


                printf("Last Name:\n");
                scanf("%s", agent.last_name);
                
                printf("Age:\n");
                scanf("%d", &agent.age);
                
                printf("Gender (M/F):\n");
                scanf("%c", &agent.gender);
                
                printf("How many assets will you be adding?\n");
                scanf("%d", noAsset);
                
                for (short int i = 0; i < noAsset; i++) {
                    printf("Please enter the AssetID\n");
                    scanf("%s", a_id);
                    registerAsset(a_id);
                }
        
                printf("Enter a mission: \n");
                scanf("%s", mission);
                //checkMission();
                //registerMission(mission);
                
                break;

            case 2:
                // Registrar mision
                char new_mission[12];
                printf("You have selected to register a mission. Please enter the ID mission:");
                scanf("%s", new_mission);
                // agregar la misión al arreglo de arreglos
                registerMission(new_mission);
                break;
            
            case 3:
                // Pedir datos de asset
                struct Asset asset;
                
                printf("Name: ");
                scanf("%s", asset.name);
                
                printf("Last name: ");
                scanf("%s", asset.last_name);
                
                printf("Asset ID: ");
                scanf("%s", asset.id);


                
                //registro
                assets[iAsset] = asset;
                iAsset++;
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