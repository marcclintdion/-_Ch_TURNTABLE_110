                           
        //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
        //------------------------------------------------------------------------------------------                                              
        #ifdef __APPLE__                                                                                                                          
       	/*
        //--------------------- 
        filePathName = [[NSBundle mainBundle] pathForResource:@"facing_UP_step" ofType:@"png"];                                                  
        image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
        glGenTextures(1, &facing_UP_HEIGHT);                                                                                                     
        glBindTexture(GL_TEXTURE_2D, facing_UP_HEIGHT);                                                                                          
        ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
        imgDestroyImage(image);                                                                                                                   
        //---------------------  
        filePathName = [[NSBundle mainBundle] pathForResource:@"facing_UP_DOT3" ofType:@"png"];                                                  
        image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
        glGenTextures(1, &facing_UP_NORMALMAP);                                                                                                     
        glBindTexture(GL_TEXTURE_2D, facing_UP_NORMALMAP);                                                                                          
        ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
        imgDestroyImage(image);                                                                                                                   
        //---------------------                                                                                                                   
        filePathName = [[NSBundle mainBundle] pathForResource:@"facing_UP" ofType:@"png"];                                                       
        image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
        glGenTextures(1, &facing_UP_TEXTUREMAP);                                                                                                       
        glBindTexture(GL_TEXTURE_2D, facing_UP_TEXTUREMAP);                                                                                            
        ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
        imgDestroyImage(image);                                                                                                                   
        */
        //-----------------------------------------------------------------------------------------------------------------------------
        spriteImage          = [UIImage imageNamed:@"facing_UP_step.png"].CGImage;
        width                    =  CGImageGetWidth(spriteImage);
        height                   =  CGImageGetHeight(spriteImage);
        spriteData            = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext      =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4,CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glGenTextures(1, &facing_UP_HEIGHT);
        glBindTexture(GL_TEXTURE_2D, facing_UP_HEIGHT);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        }  
        //==================================
        spriteImage          = [UIImage imageNamed:@"facing_UP_DOT3.png"].CGImage;
        width                    =  CGImageGetWidth(spriteImage);
        height                   =  CGImageGetHeight(spriteImage);
        spriteData            = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext      =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    
        
        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //--------
        glGenTextures(1, &facing_UP_NORMALMAP);
        glBindTexture(GL_TEXTURE_2D, facing_UP_NORMALMAP);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        }  
        //==================================
        spriteImage          = [UIImage imageNamed:@"facing_UP.png"].CGImage;
        width                    =  CGImageGetWidth(spriteImage);
        height                   =  CGImageGetHeight(spriteImage);
        spriteData            = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext      =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    
        
        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glGenTextures(1, &facing_UP_TEXTUREMAP);
        glBindTexture(GL_TEXTURE_2D, facing_UP_TEXTUREMAP);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        }  
        //==================================


        #endif                                                                                                                                    
        //============================================================================================================================                                             
        #ifdef WIN32                                                                                                                            
        loadTexture("_MODEL_FOLDERS_/facing_UP/facing_UP_step.png",             facing_UP_HEIGHT);         
        loadTexture("_MODEL_FOLDERS_/facing_UP/facing_UP_DOT3.png",          facing_UP_NORMALMAP);                                                      
        loadTexture("_MODEL_FOLDERS_/facing_UP/facing_UP.png",               facing_UP_TEXTUREMAP);                                                        
        #endif                                                                                                                                    
        //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
        #include    "facing_UP.cpp"                                                                                                                
        glGenBuffers(1,              &facing_UP_VBO);                                                                                                
        glBindBuffer(GL_ARRAY_BUFFER, facing_UP_VBO);                                                                                                
        glBufferData(GL_ARRAY_BUFFER, sizeof(facing_UP), facing_UP, GL_STATIC_DRAW);                                                                    
        glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
        //--------------------------------------------------------------------------------------------------------------------     
        #include    "facing_UP_INDICES.cpp" 
        glGenBuffers(1, &facing_UP_INDEX_VBO);                       
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facing_UP_INDEX_VBO);                   
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(facing_UP_INDICES), facing_UP_INDICES, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
        //=================================================================================================================================       
        #include "facing_UP_blocks_01/facing_UP_blocks_01_INIT.cpp"  

