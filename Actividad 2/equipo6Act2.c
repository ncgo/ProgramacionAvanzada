#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h> //libreria para el uso de expresiones regulares

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
    char mission[13];
    int numAssets;
};

//Globales
struct Agent agents[10];
struct Asset assets[100];
char mission[64][13];
FILE *fptr;


//get requests
void getAgents(int currAgents){
    for(int i = 0; i < currAgents; i++){
        printf("%d - %s %s \n", i+1, agents[i].name, agents[i].last_name);
    }
}

void getAssets(int currAssets){
    for(int i = 0; i < currAssets; i++){
        printf("%d - %s %s \n", i+1, assets[i].name, assets[i].last_name);
    }
}

void getAgentInfo(int num, int currAgents){
    if(num <= currAgents && num > 0){
        num--;
        printf("Agent Complete Name: %s %s \n", agents[num].name, agents[num].last_name);
        printf("Agent age: %d \n", agents[num].age);
        printf("Agent gender: %c \n", agents[num].gender);
        if(agents[num].numAssets>0){
            printf("Agents assets: \n");
            for(int i = 0; i < agents[num].numAssets; i++)
                printf("Asset %d, Name: %s %s\n", i+1, agents[num].asset[i].name, agents[num].asset[i].last_name);
        }
        else
        {
            printf("Agent has no assets.\n");
        }
        printf("Agent Current mission: %s\n", agents[num].mission);
    }else
    {
        printf("Invalid agent number \n");
    }
}

void getAssetInfo(int num, int currAssets){
    if(num <= currAssets && num >0){
        num--;
        printf("Asset Complete Name: %s %s \n", assets[num].name, assets[num].last_name);
        printf("Asset id: %s \n", assets[num].id);
    }else{
        printf("Asset no valido");
    }
}

void getMissions(int currMissions){
    for(int i = 0; i < currMissions; i++)
        printf("Mission %d with id: %s\n" , i+1, mission[i]);
}

//end of requests

//Registers
void registerMission(char mis[12], int currMission){
    strcpy(mission[currMission], mis);
    printf("Mission registered correctly. \n");
}

//validar que la info sea correcta
int checkName(char name[64]){ //validar nombre
    regex_t regex; //expresion regular
    int validName, valCompi;
    valCompi = regcomp(&regex, "^[A-Z]{1}[a-z]+$", REG_ICASE | REG_EXTENDED );
    validName = regexec(&regex, name, 0,NULL, 0);
    if(validName == 0){
        return 1;
    }
    else if(validName == REG_NOMATCH)
    {
        printf("Invalid name, pattern is Aaaaaa+ \n");
        return 0;
    }
    else
        return 0;

}
int checkAssetID(char id[13]){//validar ID del asset
    regex_t regex; //expresion regular
    int validID, valCompi;
    valCompi = regcomp(&regex, "^[A-Za-z]{4}[0-9]{9}$", REG_ICASE | REG_EXTENDED );
    validID = regexec(&regex, id, 0,NULL, 0);
    if(validID == 0){
        return 1;
    }
    else if(validID == REG_NOMATCH)
    {
        printf("Invalid asset ID, pattern is aaaa012345678 \n");
        return 0;
    }
    else
        return 0;
}


// mission 1 
//Access to files, ecryption and reads
void agentPrintToFile(FILE *fp, int num, int currAgents){
    if(num <= currAgents && num > 0){
        num--;
        
        fprintf(fp, "Agent Complete Name: %s %s \n", agents[num].name, agents[num].last_name);
        
        fprintf(fp, "Agent age: %d \n", agents[num].age);
        
        fprintf(fp, "Agent gender: %c \n", agents[num].gender);
        
        
        if(agents[num].numAssets>0){
            fprintf(fp, "Agents assets: \n");
            
            for(int i = 0; i < agents[num].numAssets; i++)
                fprintf(fp, "Asset %d, Name: %s %s\n", i+1, agents[num].asset[i].name, agents[num].asset[i].last_name);
        }
        else
        {
            fprintf(fp, "Agent has no assets.\n");
        }
        fprintf(fp, "Agent Current mission: %s\n", agents[num].mission);
        fprintf(fp, "----------------------------\n");
    }

}
void generateFile(int numAgents) {
    
    fptr = fopen("file.txt", "a");
    for (int i=1; i <= numAgents; i++){
        agentPrintToFile(fptr, i, numAgents);
    }
    fclose(fptr);
}
/*
void generateFile(int numAgents){
    fptr = fopen("file.txt", "a");
    fprintf(fptr, "Detailed list of current agents in system \n");
    for(int i =0; i<numAgents; i++){
        fprintf(fptr, agents[i].name);
        fprintf(fptr, agents[i].last_name);
        fprintf(fptr, agents[i].age);
        fprintf(fptr, agents[i].gender);
        fprintf(fptr, agents[i].mission);
        fprintf(fptr, agents[i].numAssets);
        for(int j=0; j<agents[i].numAssets; j++){
            fprintf(fptr, agents[i].);
            
        }
    }

    fclose(fptr);
}
*/
void readFile(){
    char chr;
    fptr = fopen("file.txt","r");
    if (fptr == NULL) {
        printf("Error reading the file\n");
    
    } else {
        while (!feof(fptr)) {
            chr = (char)(getc(fptr));
            printf("%c", chr);
        }
    }
    fclose(fptr);
}

int encryption(FILE *fp){
    return 0;
}

int checkMissionID(char id[13]){ //validar id de la mision
    regex_t regex; //expresion regular
    int validID, valCompi;
    valCompi = regcomp(&regex, "^[A-Za-z]{3}[0-9]{9}$", REG_ICASE | REG_EXTENDED );
    validID = regexec(&regex, id, 0,NULL, 0);
    if(validID == 0){
        return 1;
    }
    else if(validID == REG_NOMATCH)
    {
        printf("Invalid mission ID, pattern is aaa012345678 \n");
        return 0;
    }
    else
        return 0;
}


int main() {
    int num;
    int iAsset = 0;
    int iAgent = 0;
    int iMission = 0;
    
    do {
        printf("---------------\n");
        printf( "Select your task:\n 1. Add a new agent \n 2. Add a new mission \n 3. Add a new asset \n 4. Get Agents \n 5. Get Agent Specific Info  \n");
        printf(" 6. Get all Assets \n 7. Get Asset Specific info \n 8. Get all missions \n 9. Generate document \n 10. Read file \n 11. Quit \n");
        scanf("%d", &num);
        switch (num) {
            case 1:{
                // Registrar agente
                struct Agent agent;
                char mission[12];
                int noAsset;
                
                printf("You have chosen to add a new agent. \n Please enter the following information:\n");
                printf("First Name:\n");
                scanf("%s", agent.name);
                while(checkName(agent.name) == 0){
                    printf("Name: \n");
                    scanf("%s", agent.name);
                }


                printf("Last Name:\n");
                scanf("%s", agent.last_name);
                while(checkName(agent.last_name) == 0){
                    printf("Last Name: \n");
                    scanf("%s", agent.last_name);
                }
                
                printf("Age:\n");
                int flag = scanf("%d", &agent.age);
                // Checar edad
                if (flag == 0 || (agent.age < 1 || agent.age > 100)){
                    do {
                        printf("Invalid age. Try again.\n");
                        fflush(stdin);
                        flag = scanf("%d", &agent.age);
                    } while (flag == 0 || (agent.age < 1 || agent.age > 100));
                              
                }
                
                printf("Gender (M/F):\n");
                scanf(" %c", &agent.gender);
                //Checar genero
                while (agent.gender != 'M' && agent.gender != 'F') {
                    printf("Invalid gender. Try again\n");
                    scanf(" %c", &agent.gender);
                }
                
                printf("How many assets will you be adding?\n");
                scanf("%d", &noAsset);
                if(noAsset > 0){
                    
                    int flag = 0;
                    for (int i = 0; i < noAsset; i++)
                    {
                        
                        //bandera id correcto de asset
                        struct Asset asset;
                        flag = 0;
                        printf("Name: ");
                        scanf("%s", asset.name);
                        while(checkName(asset.name) == 0){
                            scanf("%s", asset.name);
                        }
                        
                        printf("Last name: ");
                        scanf("%s", asset.last_name);
                        while(checkName(asset.last_name) == 0){
                            printf("Last name: ");
                            scanf("%s", asset.last_name);
                        }
                        
                        while(flag != 1){
                            printf("Asset ID: ");
                            scanf("%s", asset.id);
                            flag = checkAssetID(asset.id);
                        }
                        
                        //registro
                        assets[iAsset] = asset;
                        agent.asset[i] = asset;
                        iAsset++;
                        printf("Asset registered. \n");
                    }
                    agent.numAssets = noAsset;
                }
                printf("Enter agents current mission: \n");
                scanf("%s", agent.mission);
                while (checkMissionID(agent.mission) == 0) {
                    scanf("%s", agent.mission);
                }
                
                registerMission(agent.mission, iMission);
                iMission++;
                agents[iAgent] = agent; //registro del agent en array de agentes
                iAgent++;
            }
                break;

            case 2:{
                // Registrar mision
                char new_mission[12];
                printf("You have selected to register a mission. Please enter the ID mission:");
                scanf("%s", new_mission);
                while (checkMissionID(new_mission) == 0) {
                    scanf("%s", new_mission);
                }
                // agregar la misión al arreglo de arreglos
                registerMission(new_mission, iMission);
                iMission++;
            }
                break;
            
            case 3:{
                printf("You have chosen to add a new asset. \n Please enter the following information:\n");
                // Pedir datos de asset
                struct Asset asset;
                int flag = 0;//bandera id correcto de asset
                
                printf("Name: ");
                scanf("%s", asset.name);
                
                printf("Last name: ");
                scanf("%s", asset.last_name);
                
                while(flag != 1){
                    printf("Asset ID: ");
                    scanf("%s", asset.id);
                    flag = checkAssetID(asset.id);
                }
                
                //registro
                assets[iAsset] = asset;
                iAsset++;
                printf("Asset registered. \n");
            }
                break;
            case 4:{ //Obtener los agentes y su numero asociado
                printf("You have chosen to get agents. \n ");
                printf("Current agents: \n");
                getAgents(iAgent);
                printf("Request completed \n");
                break;
            }
            case 5:{ //Info detallada de un agente
                printf("You have chosen to get specific info about an agent. \n Please enter the following information:\n");
                int agent_num;
                printf("Enter agent number: \n");
                scanf("%d", &agent_num);
                getAgentInfo(agent_num, iAgent);
                break;
            }
            case 6:{//Get all assets
                printf("You have chosen to get all assets. \n");
                printf("Current assets: \n");
                getAssets(iAsset);
                printf("Request completed \n");
                break;
            }
            case 7:{//Get asset specific info
                printf("You have chosen to get specific info about an asset. \n Please enter the following information:\n");
                int asset_num;
                printf("Enter asset number: \n");
                scanf("%d", &asset_num);
                getAssetInfo(asset_num, iAsset);
                break;
            }
            case 8:{//Get all missions
                printf("You have chosen to get all missions. \n");
                getMissions(iMission);
                break;
            }
            case 9: {//Generate file (Save it)
                printf("You have chosen to generate a file. \n");
                generateFile(iAgent);
                break;
            }
            case 10: {//Read file
                printf("You have chosen to read a file. \n");
                readFile();
                break;
            }
            case 11:
                //Salir del programa
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
        
    } while(num!=11);
    printf( "Thank you for using this application. Good luck on your mission. The Secretary is counting on you. \n" );
    return 0;
}
