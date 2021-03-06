#import <Foundation/Foundation.h>
#import "MGSMapView.h"
#import "MGSLayerController.h"

@class AGSMapView;
@class AGSGraphic;
@class AGSLocationDisplay;
@class MGSLayer;
@class MGSErrorView;

@protocol MGSAnnotation;

@interface MGSMapView () <AGSMapViewTouchDelegate, AGSCalloutDelegate, AGSMapViewLayerDelegate, AGSMapViewCalloutDelegate, AGSLayerDelegate, AGSLocationDisplayDataSourceDelegate, AGSInfoTemplateDelegate, MGSLayerControllerDelegate>
#pragma mark Properties
@property(nonatomic,weak) MGSErrorView* loadingView;
@property(nonatomic,weak) AGSMapView* mapView;

@property(nonatomic,assign,getter=areBaseLayersLoaded) BOOL baseLayersLoaded;
@property(nonatomic,strong) NSMutableDictionary* baseLayers;
@property(nonatomic,strong) NSDictionary* baseMapGroups;

@property(nonatomic,strong) NSMutableArray* externalLayers;
@property(nonatomic,strong) NSMutableSet* externalLayerManagers;
@property(nonatomic,strong) MGSLayer* defaultLayer;

@property(nonatomic, copy) dispatch_block_t pendingCalloutBlock;
@property(nonatomic, strong) id <MGSAnnotation> calloutAnnotation;
@property(nonatomic,strong) NSMutableDictionary *observerTokens;

#pragma mark Initialization
- (void)_init;
- (void)baseLayersDidFinishLoading;

#pragma mark Property Getters
- (MKCoordinateRegion)defaultVisibleArea;
- (MKCoordinateRegion)defaultMaximumEnvelope;

#pragma mark Lookup Methods
- (MGSLayerController*)layerControllerForLayer:(MGSLayer*)layer;
- (MGSLayer*)layerContainingAnnotation:(id <MGSAnnotation>)annotation;
- (MGSLayer*)layerContainingGraphic:(AGSGraphic*)graphic;
- (void)removeLayer:(MGSLayer*)layer
shoulNotifyDelegate:(BOOL)notifyDelegate;

#pragma mark AGSMapViewCalloutDelegate
- (BOOL)mapView:(AGSMapView *)mapView shouldShowCalloutForGraphic:(AGSGraphic *)graphic;
- (BOOL)mapView:(AGSMapView *)mapView shouldShowCalloutForLocationDisplay:(AGSLocationDisplay *)ld;
- (void)mapViewWillDismissCallout:(AGSMapView *)mapView;
- (void)mapViewDidDismissCallout:(AGSMapView *)mapView;

#pragma mark AGSMapViewLayerDelegate
- (void)mapViewDidLoad:(AGSMapView *)mapView;

#pragma mark AGSMapViewTouchDelegate
- (BOOL)mapView:(AGSMapView*)mapView shouldProcessClickAtPoint:(CGPoint)screen mapPoint:(AGSPoint*)mappoint;
- (void)mapView:(AGSMapView *)mapView didClickAtPoint:(CGPoint)screen mapPoint:(AGSPoint *)mappoint graphics:(NSDictionary *)graphics;

#pragma mark AGSLayerDelegate
- (void)layer:(AGSLayer *)loadedLayer didInitializeSpatialReferenceStatus:(BOOL)srStatusValid;
- (void)layer:(AGSLayer *)layer didFailToLoadWithError:(NSError *)error;

#pragma mark AGSCalloutDelegate
- (void)didClickAccessoryButtonForCallout:(AGSCallout *)callout;

#pragma mark AGSLocationDisplayDataSourceDelegate
- (void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource
                 didFailWithError:(NSError*)error;
- (void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource
             didUpdateWithHeading:(double)heading;
- (void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource
            didUpdateWithLocation:(AGSLocation*)location;
- (void)locationDisplayDataSourceStarted:(id<AGSLocationDisplayDataSource>)dataSource;
- (void)locationDisplayDataSourceStopped:(id<AGSLocationDisplayDataSource>)dataSource;
@end