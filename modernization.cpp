//*                                                                   
//*------------------------------------------------------------------*
//* Author: Dirceu Ivo (contato@bimonti.com.br)                      |
//*   Date: 26-Nov-2024                                              |
//*  Descr: Sample mainframe modernization project.                  |
//*   Inst: Compile and run.                                         |
//EXPORT   EXPORT SYMLIST=*                                          |
//LIBSINCL JCLLIB ORDER=(CBC.SCCNPRC)                                |
//*------------------------------------------------------------------*
//*                                                                   
//*------------------------------------------------------------------*
//* COMPCPGM | Compile C++ Program.                        | RC:0000 |
//*------------------------------------------------------------------*
//COMPCPGM EXEC CBCXCB,                                                
//  CPARM='OPTFILE(DD:CCOPT)',                                         
//  OUTFILE=&SYSUID..PGMLIB.PDSE(CPPSAMP)                              
//COMPILE.SYSIN DD *                                                   
#pragma runopts(POSIX(ON))                                             
#include <cstdlib>                                                     
#include <fstream>                                                     
#include <iostream>                                                    
                                                                       
int main (){                                                           
  std::system("/usr/lpp/IBM/cyp/v3r9/pyz/bin/python3 --version");      
                                                                       
  return 0;                                                            
}                                                                      
/*                                                                     
//COMPILE.CCOPT DD *                                                   
   SEARCH('CEE.SCEEH.+','CBC.SCLBH.+')                                 
   LANGLVL(EXTENDED0X)                                                 
   CSECT SO OPT XPLINK                                                 
/*                                                                     
//BIND.SYSLMOD DD DISP=SHR,DSN=&OUTFILE                                
//*                                                                   
//*------------------------------------------------------------------*
//* COPYUNIX | Copy program to Unix directory.             | RC:0000 |
//*------------------------------------------------------------------*  
//COPYUNIX EXEC PGM=BPXBATCH,PARMDD=PARMINDD                           
//STDIN    DD DUMMY                                                     
//STDOUT   DD SYSOUT=*                                                  
//STDERR   DD SYSOUT=*                                                  
//PARMINDD DD *,SYMBOLS=JCLONLY                                        
sh echo 'Start copy of program';                                 
set -o verbose ;                                           
set -o errexit ;                                           
set -x ;                                                   
cp "//'&SYSUID..PGMLIB.PDSE(CPPSAMP)'" /z/z00379/cppsamp.c 
//*
//*------------------------------------------------------------------*
//* EXECCPGM | Execute the C++ program.                    | RC:0000 |
//*------------------------------------------------------------------*
//EXECCPGM EXEC PGM=BPXBATCH,PARM='PGM /z/z00379/cppsamp.c'   
//SYSOUT   DD SYSOUT=*                                      
//STDOUT   DD SYSOUT=*                                      
//STDERR   DD SYSOUT=*                                      
