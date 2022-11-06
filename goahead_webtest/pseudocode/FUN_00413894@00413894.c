
void FUN_00413894(int param_1,int param_2,char *param_3,int param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  uVar2 = *(uint *)(param_1 + 0x100);
  uVar3 = uVar2 & 0xfffffffd;
  *(uint *)(param_1 + 0x100) = uVar3;
  if ((uVar2 & 0x40000) == 0) {
    *(uint *)(param_1 + 0x100) = uVar3 | 0x40000;
    if (param_4 == 0) {
      uVar4 = FUN_00411fa0(param_2);
      pcVar7 = "HTTP/1.1 %d %s\r\n";
    }
    else {
      uVar4 = FUN_00411fa0(param_2);
      pcVar7 = "HTTP/1.0 %d %s\r\n";
    }
    websWrite(param_1,pcVar7,param_2,uVar4);
    websWrite(param_1,"Server: %s/%s\r\n","RSS-Webs","1.4b191");
    iVar5 = websGetDateString(0);
    if (iVar5 != 0) {
      websWrite(param_1,"Date: %s\r\n",iVar5);
      bfree(iVar5);
    }
    if (param_2 == 0x191) {
      if ((*(uint *)(param_1 + 0x100) & 0x20000) == 0) {
        websWrite(param_1,"WWW-Authenticate: Basic realm=\"%s\"\r\n",s_GoAhead_00430134);
      }
      else {
        uVar4 = websCalcNonce(param_1);
        uVar6 = websCalcOpaque(param_1);
        websWrite(param_1,
                  "WWW-Authenticate: Digest realm=\"%s\", domain=\"%s\",qop=\"%s\", nonce=\"%s\", opaque=\"%s\",algorithm=\"%s\", stale=\"%s\"\r\n"
                  ,s_GoAhead_00430134,DAT_00430c14,&DAT_0041ec70,uVar4,uVar6,&DAT_0041ec78,"FALSE");
        bfree(uVar4);
        bfree(uVar6);
      }
    }
    if ((*(uint *)(param_1 + 0x100) & 2) != 0) {
      websWrite(param_1,"Connection: keep-alive\r\n");
    }
    websWrite(param_1,"Pragma: no-cache\r\nCache-Control: no-cache\r\n");
    websWrite(param_1,"Content-Type: text/html\r\n");
    if ((param_4 != 0) &&
       (websWrite(param_1,"Location: %s\r\n",param_4), puVar1 = PTR_newUserSessionID_004306e0,
       *PTR_newUserSessionID_004306e0 != '\0')) {
      websWrite(param_1,"Set-Cookie: %s%s;path=/\r\n","SESSIONID=",PTR_newUserSessionID_004306e0);
      *puVar1 = 0;
    }
    websWrite(param_1,"\r\n");
  }
  if ((((*(uint *)(param_1 + 0x100) & 0x200) == 0) && (param_3 != (char *)0x0)) &&
     (*param_3 != '\0')) {
    websWrite(param_1,"%s\r\n",param_3);
  }
  websDone(param_1,param_2);
  return;
}

