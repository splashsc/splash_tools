
void FUN_0041ca50(void)

{
  code **ppcVar1;
  
  for (ppcVar1 = (code **)&DAT_0043000c; *ppcVar1 != (code *)0xffffffff; ppcVar1 = ppcVar1 + -1) {
    (**ppcVar1)();
  }
  return;
}

