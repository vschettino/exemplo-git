#include math.io

/* 
calculates the available memory in the system
*/
int main()
{
    int mem = 0;
    mem = getAvailableMemory();
    printf("Available memory: %d", mem);
    printf("Available cpus: %d", getAvailableCpus());
    return 0;
}

getAvailableMemory(){
    int mem = 0;
    FILE *fp;
    char buffer[100];
    fp = popen("free -m | grep Mem | awk '{print $7}'", "r");
    fgets(buffer, 100, fp);
    mem = atoi(buffer);
    pclose(fp);
    return mem;
}

getAvailableCpus(){
    int cpus = 0;
    FILE *fp;
    char buffer[100];
    fp = popen("cat /proc/cpuinfo | grep processor | wc -l", "r");
    fgets(buffer, 100, fp);
    cpus = atoi(buffer);
    pclose(fp);
    return cpus;
}