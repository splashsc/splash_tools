int __fastcall sub_4CAA38(int a1)
{
  const char *v1; // $v0
  char *v2; // $v1
  int v3; // $t2
  int v4; // $t1
  int v5; // $t0
  int v6; // $a3
  __int16 v7; // $t0
  char v8; // $a3
  int v9; // $v0
  char v11[2052]; // [sp+18h] [-804h] BYREF

  v1 = "{\"ret\":\"1\",\"msg\":\"ok\",\"data\":{\"countdownStatus\":\"off\",\"switchoverPic\":[],\"templateMark\":\"1\",\""
       "androidStartupVideo\":[],\"advertisingVideo\":[],\"countdown\":30,\"advertisingPic\":[],\"switchoverText\":\"\",\""
       "startupVideo\":[],\"welcome\":{\"Chinese\":{\"appellation\":\"\",\"position\":\"\",\"text\":\"\",\"place\":\"\",\""
       "title\":\"\",\"signPic\":\"\",\"logo\":\"\",\"signText\":\"\",\"signType\":\"text\"},\"English\":{\"appellation\""
       ":\"\",\"position\":\"\",\"text\":\"\",\"place\":\"\",\"title\":\"\",\"signPic\":\"\",\"logo\":\"\",\"signText\":\""
       "\",\"signType\":\"text\"}},\"backgroundVideo\":[],\"backgroundMusic\":[],\"backgroundPic\":[]}}";
  v2 = v11;
  do
  {
    v3 = *(_DWORD *)v1;
    v4 = *((_DWORD *)v1 + 1);
    v5 = *((_DWORD *)v1 + 2);
    v6 = *((_DWORD *)v1 + 3);
    v1 += 16;
    *(_DWORD *)v2 = v3;
    *((_DWORD *)v2 + 1) = v4;
    *((_DWORD *)v2 + 2) = v5;
    *((_DWORD *)v2 + 3) = v6;
    v2 += 16;
  }
  while ( v1 != "}}" );
  v7 = *(_WORD *)v1;
  v8 = v1[2];
  v9 = *(_DWORD *)(a1 + 36) | 0x8000;
  v2[2] = v8;
  *(_WORD *)v2 = v7;
  *(_DWORD *)(a1 + 36) = v9;
  return httpd_cgi_ret(a1, v11, 546, 4);
}

