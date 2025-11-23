void search(int key)
{
  int i,index;
  i = hash_fun(key);
  index=i;
  while(array[i].flag!=0)
  {
    if(array[i].flag==1 && array[i].data->key==key)
    {
      printf("key is found\n");
      return;
    }
    i = (i+1)%MAX
    if(i==index)
      break;
  }
  printf("Not found\n");
}

void remove_key(int key)
{
  int index = hash_fun(key);
  int i = index;
  while(array[i].flag!=0)
  {
    if(array[i].data->key==key)
    {
      array[i].flag=2;
      array[i].data=NULL;
      return;
    }
    i = (i+1)%MAX;
    if(i==index)
      break;
  }
  printf("Element not found\n");
  return;
}
