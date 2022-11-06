
void websHeader2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  websWrite(param_1,"HTTP/1.0 200 OK\n",param_3,param_4,&_mips_gp0_value);
  websWrite(param_1,"Server: %s/%s\r\n","RSS-Webs","1.4b191");
  websWrite(param_1,"Pragma: no-cache\n");
  websWrite(param_1,"Cache-control: no-cache\n");
  websWrite(param_1,"Content-Type: text/html\n");
  websWrite(param_1,"\n");
  return;
}

