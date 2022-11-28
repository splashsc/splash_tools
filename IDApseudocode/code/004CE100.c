ssize_t __fastcall ApiAddWhiteIp(int a1, int a2, int a3, int a4, struct sockaddr *a5, socklen_t *a6)
{
  int v6; // $a0
  void *v7; // $a1
  size_t v8; // $a2
  int v9; // $a3

  MEMORY[0]();
  return recvfrom(v6, v7, v8, v9, a5, a6);
}
// 4CE109: variable 'v6' is possibly undefined
// 4CE109: variable 'v7' is possibly undefined
// 4CE109: variable 'v8' is possibly undefined
// 4CE109: variable 'v9' is possibly undefined

