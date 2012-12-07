//
//  Cocoa XML-RPC Client Framework
//  XMLRPCConnection.h
//
//  Created by Eric J. Czarny on Thu Jan 15 2004.
//  Copyright (c) 2004 Divisible by Zero.
//

//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without 
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or 
//  sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//
 
#import <Foundation/Foundation.h>

@class XMLRPCRequest, XMLRPCResponse;

/* XML-RPC Connecion Notifications */

@interface XMLRPCConnection : NSObject {
	NSURLConnection *connection;
	id delegate;
	XMLRPCRequest* request;
	//
	NSMutableData* retData;
}


@property (nonatomic, retain) NSURLConnection* connection;
@property (nonatomic, retain) id delegate;
@property (nonatomic, retain) XMLRPCRequest* request;
@property (nonatomic, retain) NSMutableData* retData;


#pragma mark -

+ (XMLRPCConnection*)sendAsynchronousXMLRPCRequest: (XMLRPCRequest *)req delegate: (id) callback;
+ (NSData*) sendSynchronousRequest:(XMLRPCRequest*)request returningResponse:(NSURLResponse**)response error:(NSError**)error;
#pragma mark -

- (void)cancel;

@end

#pragma mark -

@interface NSObject (XMLRPCConnectionDelegate)

- (void)xmlrpcDone: (XMLRPCConnection *)connection isSucceeded: (BOOL)succeeded retObject: (id)ret forMethod: (NSString *)method;

@end

#pragma mark -