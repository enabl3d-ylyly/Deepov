# -*- coding: utf-8 -*-
"""
Created on Sun Nov  8 21:16:15 2015

@author: navid
"""

import scipy.optimize
from tuner import *
from deepovFunction import *
from interface import *

def opt_BasinHopping(init_guess,niter):
#    scipy.optimize.basinhopping(evaluate,init_guess,niter,T=100.,)
    return value

def opt_gridSearch(parametersList):
    # TODO : use numpy arrays instead of lists to optimize speed
    """ Does a simple grid search over the parameter space and returns the elo win and the best values in a dictionnary"""
    elo = -10000 # Stores the final score for best case
    values = list() # Stores the results
    n = len(parametersList) # dimension of the problem = number of parameters
    
    # Iterates over the the parameters to initialize values list
    # The parameter temporary value does not need an initial guess in grid search and is set as the lower bound
    for i in range(0,n):
        parametersList[i][4] = parametersList[i][1]
        values.append(parametersList[i][1])
        

    # Goes over the paramter space and launch cutechess at each point
    recursive_iterate(parametersList,0,n,values,elo)
    
    return value,elo
    
def recursive_iterate(parametersList,i,max_dim,values,elo):
    """ Recursive iteration  along the dimension current_dim """
    # At the leave of the tree
    if (i == max_dim):
        while ( parametersList[count][4] <= parametersList[count][2] ):
            # step 1 : evaluate the score at current leave
            parameters = setParam(parametersList)
            command = generateCommand(parameters)
            score = evaluate(command)
            if score > elo:
                values = [parametersList[j][4] for j in range(0,max_dim)]          
                elo = score
                
            # step 2 : at end of evaluation, increment current leave
            parametersList[i][4] += parametersList[i][3]

        # step 3 : at end of loop, reinitialize the leave at lower bound
        parametersList[i][4] = parametersList[i][1]
        
    else:
        while ( parametersList[i][4] <= parametersList[i][2] ):
            # step 1b : if not at leave, recursive call at dim i+1
            recursive_iterate(parametersList,i+1,max_dim,values,elo)
            # step 2b : at end of evaluation, increment current dim
            parametersList[i][4] += parametersList[i][3]

         
        # step 3b : at end of loop, reinitialize the dim at lower bound and i++
        parametersList[i][4] = parametersList[i][1]
            