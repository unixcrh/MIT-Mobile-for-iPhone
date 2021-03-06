#import <UIKit/UIKit.h>
#import <ArcGIS/ArcGIS.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import "MGSAnnotation.h"

FOUNDATION_EXTERN NSString* const MGSAnnotationAttributeKey;

typedef NS_ENUM(NSUInteger,MGSGraphicType) {
    MGSGraphicDefault = 0,
    MGSGraphicStop
};

FOUNDATION_EXPORT AGSPoint* AGSPointFromCLLocationCoordinate2D(CLLocationCoordinate2D coord);
FOUNDATION_EXPORT AGSPoint* AGSPointFromCLLocationCoordinate2DInSpatialReference(CLLocationCoordinate2D coord, AGSSpatialReference *targetReference);
FOUNDATION_EXPORT CLLocationCoordinate2D CLLocationCoordinate2DFromAGSPoint(AGSPoint *point);
FOUNDATION_EXPORT MKCoordinateRegion MKCoordinateRegionFromAGSEnvelope(AGSEnvelope *envelope);
FOUNDATION_EXPORT AGSEnvelope* AGSEnvelopeFromMKCoordinateRegion(MKCoordinateRegion region);
FOUNDATION_EXPORT AGSEnvelope* AGSEnvelopeFromMKCoordinateRegionWithSpatialReference(MKCoordinateRegion region, AGSSpatialReference *reference);