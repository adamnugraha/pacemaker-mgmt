/*
 * resource_clone_provider.c: HA_ResourceClone provider
 * 
 * Author: Jia Ming Pan <jmltc@cn.ibm.com>
 * Copyright (c) 2005 International Business Machines
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#include <portability.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cmpidt.h>
#include <cmpift.h>
#include <cmpimacs.h>
#include <hb_api.h>
#include "cmpi_utils.h"
#include "cluster_info.h"
#include "resource_common.h"

static const char * PROVIDER_ID = "cim-clone";
static char G_classname []      = "HA_ResourceClone";
static CMPIBroker * G_broker    = NULL;

DeclareInstanceFunctions(ResourceClone);

/**********************************************
 * Instance provider functions
 **********************************************/

static CMPIStatus 
ResourceCloneCleanup(CMPIInstanceMI * mi, CMPIContext * ctx)
{
        CMPIStatus rc;
        resource_cleanup(G_broker, G_classname, mi, ctx, TID_RES_CLONE, &rc);
	CMReturn(CMPI_RC_OK);
}

static CMPIStatus 
ResourceCloneEnumInstanceNames(CMPIInstanceMI * mi, CMPIContext * ctx,
                              CMPIResult * rslt, CMPIObjectPath * ref)
{
        CMPIStatus rc;

        init_logger( PROVIDER_ID );
        cl_log(LOG_INFO, "%s", G_classname);
    
        if ( enum_inst_resource(G_broker, G_classname, ctx, rslt, ref, 0, 
                                TID_RES_CLONE, &rc) == HA_OK ) {
                CMReturn(CMPI_RC_OK);	
        } else {
                CMReturn(CMPI_RC_ERR_FAILED);
        }
}


static CMPIStatus 
ResourceCloneEnumInstances(CMPIInstanceMI * mi, CMPIContext * ctx,
                          CMPIResult * rslt, CMPIObjectPath * ref,
                          char ** properties)
{
        CMPIStatus rc;

        init_logger( PROVIDER_ID );
        if ( enum_inst_resource(G_broker, G_classname, ctx, rslt, ref, 1, 
                                TID_RES_CLONE, &rc) == HA_OK ) {
                CMReturn(CMPI_RC_OK);	
        } else {
                CMReturn(CMPI_RC_ERR_FAILED);
        }
        CMReturn(CMPI_RC_OK);	

}

static CMPIStatus 
ResourceCloneGetInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                        CMPIResult * rslt, CMPIObjectPath * cop,
                        char ** properties)
{
        CMPIStatus rc;
        init_logger( PROVIDER_ID );
        
        if ( get_inst_resource(G_broker, G_classname, ctx, rslt, cop, properties, 
                            TID_RES_CLONE, &rc) == HA_OK ) {
                CMReturn(CMPI_RC_OK);
        } else {
                CMReturn(CMPI_RC_ERR_FAILED);
        }
}

static CMPIStatus 
ResourceCloneCreateInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                           CMPIResult * rslt, CMPIObjectPath * cop,
                           CMPIInstance * ci)
{
	CMPIStatus rc = {CMPI_RC_OK, NULL};
	CMSetStatusWithChars(G_broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
	return rc;
}


static CMPIStatus 
ResourceCloneSetInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                        CMPIResult * rslt, CMPIObjectPath * cop,
                        CMPIInstance * ci, char ** properties)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
        CMSetStatusWithChars(G_broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
        return rc;
}


static CMPIStatus 
ResourceCloneDeleteInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                           CMPIResult * rslt, CMPIObjectPath * cop)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
        CMSetStatusWithChars(G_broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
	return rc;
}

static CMPIStatus 
ResourceCloneExecQuery(CMPIInstanceMI * mi, CMPIContext * ctx,
                      CMPIResult * rslt, CMPIObjectPath * ref,
                      char * lang, char * query)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
        CMSetStatusWithChars(G_broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
	return rc;
}


/**************************************************
 * Method Provider 
 *************************************************/
static CMPIStatus 
ResourceCloneInvokeMethod(CMPIMethodMI * mi, CMPIContext * ctx,
                         CMPIResult * rslt, CMPIObjectPath * ref,
                         const char * method, CMPIArgs * in, CMPIArgs * out)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
        CMSetStatusWithChars(G_broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
	return rc;    
}


static CMPIStatus 
ResourceCloneMethodCleanup(CMPIMethodMI * mi, CMPIContext * ctx)
{
        CMReturn(CMPI_RC_OK);
}


/*****************************************************
 * install provider
 ****************************************************/

DeclareInstanceMI(ResourceClone, HA_ResourceCloneProvider, G_broker);
DeclareMethodMI(ResourceClone, HA_ResourceCloneProvider, G_broker);
