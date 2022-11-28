int __fastcall system(char *command)
{
  MEMORY[0](command);
  return create_dir2();
}
// 4CD740: using guessed type int create_dir2(void);

