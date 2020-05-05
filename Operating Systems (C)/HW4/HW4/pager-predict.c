/*
 * File: pager-predict.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains a predictive pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    /* Local vars */
    int proctmp;
    int pagetmp;
    int page;
    int lru;
    int proc;
    int pc;

    /* initialize static vars on first run */
    if(!initialized){
        for(proctmp=0; proctmp < MAXPROCESSES; proctmp++){
            for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++){
                timestamps[proctmp][pagetmp] = 0;
            }
        }
        initialized = 1;
    }

    for(proc=0; proc<MAXPROCESSES; proc++) 
    {
        if(q[proc].active) 
        {
            pc = q[proc].pc;
            printf("%d",pc);
			page = pc/PAGESIZE;
            
            timestamps[proc][page] = tick;
            
            if(!q[proc].pages[page]) //Not swapped in
            {
                if(!pagein(proc,page)) //Can't start swap
                {
                    lru = timestamps[proc][page];
                    
                    for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++)//Go through pages
                    {						
						if(timestamps[proc][pagetmp] < lru)//Check if this timestamp was more lru than previous lru
						{	
							if(q[proc].pages[pagetmp])//Check if in	
							{			
								lru = pagetmp;//Set new lru to this
							}
											
						}
                    }
                    pageout(proc,lru);//Pageout lru
                }
            }
        }
	}

    /* advance time for next pageit iteration */
    tick++;
} 
