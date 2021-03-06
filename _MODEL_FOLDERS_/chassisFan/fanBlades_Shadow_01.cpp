glBindBuffer(GL_ARRAY_BUFFER, fanBlades_VBO);    
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, fanBlades_INDICES_VBO);                                                                                                                                 
//=================================================================================================================     
    
       //---------------------------------------------------------------------------
       Translate(LightModelViewMatrix, fanBlades_POSITION[0] * scaleMoveShadows[0], 
                                       fanBlades_POSITION[1] * scaleMoveShadows[1], 
                                       fanBlades_POSITION[2] * scaleMoveShadows[2]);        
       //---------------------------------------------------------------------------
       Rotate(LightModelViewMatrix,    fanBlades_ROTATE[0], 
                                       fanBlades_ROTATE[1], 
                                       fanBlades_ROTATE[2], 
                                       fanBlades_ROTATE[3]);        

 
//=================================================================================================================         
SelectShader(shaderNumber);
//=================================================================================================================
                                                                                                                                           
    //--------------------------------------------------------------------------------------------------------------------      
    glDrawElements(GL_TRIANGLES, 1734, GL_UNSIGNED_INT, 0);  
