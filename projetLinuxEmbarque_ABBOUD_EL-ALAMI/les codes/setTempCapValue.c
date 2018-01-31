#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
  
int  main()
{
  /*char id[50];
  char port[50];
  char idx[50];
  char value[50];
  scanf("%s",id);
  scanf("%s",port);
  scanf("%s",idx);
  scanf("%s",value);
  char url[300];
  strcpy (url,"http://");
  strcat (url,id);
  strcat (url,":");
  strcat (url,port);
  strcat (url,"/");
  strcat (url,"json.htm?type=command&param=udevice&idx=");
  strcat (url,idx);
  printf("\n%s",url);
  char postdata[300];
  strcpy (postdata,"svalue=");
  strcat(postdata,value);*/
  char url[]="http://172.20.13.30:8080//json.htm?type=command&param=udevice&idx=7&nvalue=0";
  char postdata[]="svalue=1000";
  printf("\n%s",url);
  
  CURL *curl;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */ 
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    curl_easy_setopt(curl, CURLOPT_URL,&url);
    /* Now specify the POST data */ 
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &postdata);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}

